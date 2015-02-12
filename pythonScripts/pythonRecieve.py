#!/usr/bin/env python3
from OSC import OSCServer, OSCClient, OSCMessage
from sys import argv
from time import sleep
import pdb
import re
from collections import OrderedDict
server = OSCServer( ("localhost", 8338) )
server.timeout = 0
run = True


client = OSCClient()
client.connect(('127.0.0.1', 8339))
# Other

dict_gestures = {}
index=  {"id":0, "expression":1, "gesture_mouth_width":2, "gesture_mouth_height": 3, 
        "gesture_eyebrow_left":4, "gesture_eyebrow_right":5,"gesture_eye_left":6, 
        "gesture_eye_right": 7, "gesture_jaw":8,"gesture_nostrils":9,
        "pose_scale": 10}
# this method of reporting timeouts only works by convention
# that before calling handle_request() field .timed_out is 
# set to False
def handle_timeout(self):
    self.timed_out = True

# funny python's way to add a method to an instance of a class
import types
server.handle_timeout = types.MethodType(handle_timeout, server)


def read_csv():
    fd = open('face_gestures.csv','r+')
    for line in fd:
        pass
    next_id = line.split(",")[0]

    # Its the first row.
    if(next_id == "id"):
        next_id = 0
    else:
        next_id = int(next_id) + 1

    global dict_gestures
    pdb.set_trace()
    dict_gestures["id"] = next_id


def user_callback(path, tags, args, source):
    # which user will be determined by path:
    # we just throw away all slashes and join together what's left
    user = ''
    # We split it by '/' and ignore the first index as it has no useful
    # information
    column_name = path.split("/")[1::]

    print path,args

    oscmsg = OSCMessage()
    oscmsg.setAddress(path)
    oscmsg.append(args)
    client.send(oscmsg)
 
    # tags will contain 'fff'
    # args is a OSCMessage with data
    # source is where the message came from (in case you need to reply)
    
def quit_callback(path, tags, args, source):
    # don't do this at home (or it'll quit blender)
    global run
    run = False




# user script that's called by the game engine every frame
def each_frame():
    # clear timed_out flag
    server.timed_out = False
    # handle all pending requests then return
    while not server.timed_out:
        server.handle_request()

def main():
    # Initialize messages to look for.
    server.addMsgHandler( "/found", user_callback )
    server.addMsgHandler( "/pose/position", user_callback )
    server.addMsgHandler( "/pose/scale", user_callback )
    server.addMsgHandler( "/pose/orientation", user_callback )
    server.addMsgHandler( "/gesture/mouth/width", user_callback )
    server.addMsgHandler( "/gesture/mouth/height", user_callback )
    server.addMsgHandler( "/gesture/eyebrow/left", user_callback )
    server.addMsgHandler( "/gesture/eyebrow/right", user_callback )
    server.addMsgHandler( "/gesture/eye/left", user_callback )
    server.addMsgHandler( "/gesture/eye/right", user_callback )
    server.addMsgHandler( "/gesture/jaw", user_callback )
    server.addMsgHandler( "/gesture/nostrils", user_callback)
    # simulate a "game engine"
    read_csv()
    while run:
        # do the game stuff:
        # call user script
        each_frame()
        # Now handle scikit in a different thread.
        # Should grab the csv data. Parse it, and be able to classify using KNN or by other
        # means.
        # -The file should be. To use a simple KNN to identify if happy, or neutral.
        # get_userExpression()

    server.close()

if __name__ == "__main__":
    print "eep"
    main()