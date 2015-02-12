from __future__ import division
import numpy as np
from sklearn import hmm
import pdb

model = hmm.GaussianHMM(4,"full")

X = [  [1,2,5,4],
	   [1,3,2,8],
	   [3,4,5,9],
	   [1,2,9,6]]


Y = [ [1,2,3]]
X = np.array(X)
model.fit([X])

pdb.set_trace()

print "Debug!"