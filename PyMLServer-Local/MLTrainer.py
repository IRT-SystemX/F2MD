"""
/*******************************************************************************
 * @author  Joseph Kamel
 * @email   josephekamel@gmail.com
 * @date    28/11/2018
 * @version 2.0
 *
 * SCA (Secure Cooperative Autonomous systems)
 * Copyright (c) 2013, 2018 Institut de Recherche Technologique SystemX
 * All rights reserved.
 *******************************************************************************/
"""
from sklearn.neural_network import MLPClassifier
from sklearn.svm import SVC
from sklearn import datasets
from sklearn.externals import joblib
from os import listdir
from os.path import isfile, join
import numpy as np

from keras.models import Sequential  
from keras.layers.core import Dense, Activation, Dropout  
from keras.layers.recurrent import LSTM

from keras.models import load_model

from keras.utils import to_categorical

class MlTrainer:

	AIType = 'NotSet'

	valuesFileStr = 'notSet'
	targetFileStr = 'notSet'
	savePath = ''

	valuesCollection = np.array([])
	targetCollection = np.array([])

	curDateStr = ''
	def setCurDateSrt(self, datastr):
		self.curDateStr = datastr

	def setSavePath(self, datastr):
		self.savePath = datastr

	def setValuesCollection(self, datacol):
		self.valuesCollection = datacol

	def setTargetCollection(self, datacol):
		self.targetCollection = datacol

	def setAIType(self, datastr):
		self.AIType = datastr

	def train(self):

		if(self.AIType == 'SVM'):
			X, y = self.valuesCollection, self.targetCollection
			y = to_categorical(y)
			clf = SVC(gamma=0.001, C=100.)
			clf.fit(X, y)

		if(self.AIType == 'MLP_L1N15'):
			X, y = self.valuesCollection, self.targetCollection
			y = to_categorical(y)
			clf = MLPClassifier(solver='lbfgs', alpha=1e-5,hidden_layer_sizes=(25,), random_state=1)
			clf.fit(X, y)
		if(self.AIType == 'MLP_L3N25'):
			X, y = self.valuesCollection, self.targetCollection
			y = to_categorical(y)
			clf = MLPClassifier(solver='lbfgs', alpha=1e-5,hidden_layer_sizes=(25,25,25,), random_state=1)
			clf.fit(X, y)

		if(self.AIType == 'LSTM'):
			print self.valuesCollection.shape
			print self.targetCollection.shape
			X, y = self.valuesCollection, self.targetCollection
			y = to_categorical(y)
			clf = Sequential()  
			clf.add(LSTM(128, return_sequences=True, input_shape=(X.shape[1], X.shape[2])))
			clf.add(LSTM(128, return_sequences=True))
			clf.add(LSTM(128, return_sequences=False))
			clf.add(Dense(y.shape[1],activation='softmax'))  
			clf.compile(loss='categorical_crossentropy', optimizer='adam',metrics=['accuracy'])
			clf.fit(X, y,epochs=10, batch_size=64)  

		joblib.dump(clf, self.savePath + '/clf_' + self.AIType + '_'+self.curDateStr+'.pkl')

	def loadData(self):
		self.valuesCollection = np.load(self.savePath + '/' +self.valuesFileStr)
		self.targetCollection = np.load(self.savePath + '/' +self.targetFileStr)

	def setFileNames(self):
		filesNames = [f for f in listdir(self.savePath) if isfile(join(self.savePath, f))]
		for s in filesNames:
			if s.endswith(".npy"):
				if s.startswith("valuesSave_") and self.valuesFileStr == 'notSet' :
					self.targetFileStr = s
				if s.startswith("targetSave_") and self.targetFileStr == 'notSet' :
					self.targetFileStr = s
