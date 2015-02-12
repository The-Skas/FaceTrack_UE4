#!/usr/bin/env python3
from OSC import OSCServer, OSCClient, OSCMessage
import sys
from time import sleep
import pdb
server = OSCServer( ("localhost", 8339) )
server.timeout = 0
run = True
dict_gestures = {}
current_expression = "neutral"

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
    for line in fh:
        pass
    next_id = int(line.split(",")[0]) + 1

    dict_gestures["id"] = next_id

    dict_gestures["expression"] = current_expression


def user_callback(path, tags, args, source):
    # which user will be determined by path:
    # we just throw away all slashes and join together what's left
    user = ''
    # We split it by '/' and ignore the first index as it has no useful
    # information
    column_name = path.split("/")[1::]

    # We join the column name into a single string.
    column_name = "_".join(column_name)

    if(column_name == "found"):
        write_gestures_to_csv()
    else:
        # Doesnt handle arrays
        global dict_gestures
        dict_gestures[column_name] = args[0]

    # tags will contain 'fff'
    # args is a OSCMessage with data
    # source is where the message came from (in case you need to reply)
    
def quit_callback(path, tags, args, source):
    # don't do this at home (or it'll quit blender)
    global run
    run = False

def write_gestures_to_csv():
    global dict_gestures

    # We make sure dictionary gestures contains elements.
    if(dict_gestures):
        fd = open('face_gestures.csv','a')
        row = re.sub('[\[\]]', '', dict_gestures.values())
        fd.write(row)
        fd.close()

        old_id = dict_gestures["id"]
        del dict_gestures
        dict_gestures["id"] = int(old_id) + 1

        dict_gestures["expression"] = current_expression


# user script that's called by the game engine every frame
def each_frame():
    # clear timed_out flag
    server.timed_out = False
    # handle all pending requests then return
    while not server.timed_out:
        server.handle_request()

def main():

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
    while run:
        # do the game stuff:
        # call user script
        each_frame()

    server.close()

if __name__ == "__main__":
    print "eep"
    main()