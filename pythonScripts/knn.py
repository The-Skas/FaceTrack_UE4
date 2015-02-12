
from sklearn.neighbors import KNeighborsClassifier
import numpy as np
import pandas as pd
import csv as csv



def buildKNN(file,PCA=False):
	df = pd.read_csv(file, header=0)

	# Store the id column before dropping it
	id_column =df["id"]
	# Drop it from th
	df = df.drop(["id"],axis=1)
	# Convert to usable format
	train_data = df.values


	# Initialize KNN
	neigh =KNeighborsClassifier()
	neigh.fit(train_data[0::,1::],train_data[0::,0])

	return neigh

def buildKNN_PCA():
	""" This uses PCA to build KNN, after reading an article explaining
	the pitfalls that larger values might cause."""

print "done"