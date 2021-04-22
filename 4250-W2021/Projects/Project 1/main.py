import math
import time
from itertools import combinations
import numpy


class BitVector:
    mainVector = b'\x80\x40\x20\x10\x08\x04\x02\x01'

    def __init__(self, size: float):
        length = math.ceil(size/8)
        self.bitVector = bytearray(length)

    def getPOS(pos: int) -> tuple:
        return math.floor(pos/8), pos%8

    def getBit(self, pos: int) -> bool:
        pos = BitVector.getPOS(pos)
        check = self.mainVector[pos[1]] & self.bitVector[pos[0]]
        if check == 0:
            return False
        else:
            return True

    def flipBit(self, pos: int):
        pos = BitVector.getPOS(pos)
        self.bitVector[pos[0]] ^= self.mainVector[pos[1]]

    def setBit(self, pos: int):
        pos = BitVector.getPOS(pos)
        self.bitVector[pos[0]] |= self.mainVector[pos[1]]

    def resetBit(self, pos: int):
        pos = BitVector.getPOS(pos)
        self.bitVector[pos[0]] &= ~self.mainVector[pos[1]]

class APriori:
    #This is the initiaion class
    #input: the file path ro the data, the support, and the size of the data chunk
    def __init__(self, fp: str, supp: int, dataSize: int):
        with open(fp, "r", encoding="utf-8") as file:
            self.dataFile = file.read().splitlines()
        self.supp = ((supp/100) * len(self.dataFile)) * (dataSize/100)
        self.EOF = int(len(self.dataFile) * (dataSize/100))

    #This defintion will actually exevute the APriori algorithm
    def execute(self):
        startTime = time.perf_counter()

        '''==== First =====
           In this pass we are simply finding all singletons frequency.'''
        
        #This dictionary will hold each item as a key and each its frequency as its key
        freqItemCount = {}

        #for each line in the file
        for line in range(self.EOF):
            #the current basket consists of the line of items split up
            currentBasket = self.dataFile[line].split()

            #for each item in the basket 
            for item in currentBasket:
                #if the item has not occured and be recorded, do so
                if item not in freqItemCount:
                    freqItemCount[item] = 1
                #if the item has occured int he past, simply increment the freq   
                else:
                    freqItemCount[item] += 1

            #from the list of items and their freq values, we will aggriate and remove
            #all items that do not meet the support value

            #this list will simply hold the freq values of each word
        freqItemList = []

        #for each item in the freqItemCount dictionarty obtain the key into the item var
        for item in freqItemCount.keys():
            #if the item at key "item" is greater or equal to the support
            if freqItemCount[item] >= self.supp:
                #record the items (key) into the item list
                freqItemList.append(item)
            #if not, do nothing
            else:
                continue

        #del will remove this variable and its contents from main memeory for
        #performace reasons
        del freqItemCount

        '''==== Second Pass ====
           This pass will begin to establish pairs where both individual
           items in the pair are frequent themselves'''

        #This dictionary will hold the pair as keys and the values will be 
        candidatePairs = {}

        #We will then establish all unique pairs into a list, storing them into a list
        #We will use the combinations tool provided by itertools library for ease
        #we will use the freqItemList from first pass as they are all freq items, and for
        #pair to hold as freq, all items within the pair set must individually supported
        pairList = combinations(freqItemList, 2)
        
        #We will then initiate a dictionary, or bucket list, for the cadidate pairs. The dictionary
        #size will be equaly to the number of pairs. Each key will be initated with a value of 0. 
        for eachPair in pairList:
            candidatePairs[eachPair] = 0

        #There is now a "basket"(key-value pair) for each pair
        # we will now, again, iterate throught he data set and extract baskets(lines) and seperate items into pairs
        for line in range(self.EOF):
            currentBasket = self.dataFile[line].split()
            #we will now establish a list of pairs from each basket
            pairs = combinations(currentBasket, 2)
            #we will now start to establish and record the freq of each cadidate pair
            for pair in pairs:
                if pair in candidatePairs:
                    candidatePairs[pair] += 1

        #These lists are deleted for performance reasons
        del pairList
        del pairs
    

        #we will now create a set of frequent pairs
        freqPairsSet = set()
        #for eacg item in the candidatePairs dictionary, obtain the key into the item var
        for item in candidatePairs.keys():
            #if the candiate paits support value is >= to the support, add tot he freqPairsSet set
            if candidatePairs[item] >= self.supp:
                freqPairsSet.add(item)

        #this dict is deleted for performace reasons
        del candidatePairs

        endTime = time.perf_counter()
        runTime = ((endTime-startTime) * 1000)

        print(f'A Priori run time: {runTime:.02f} ms')
        print("List of frequent pairs: " + str(len(freqPairsSet)))

        del freqPairsSet

class PCY:
    #initiation class
    def __init__(self, fp: str, supp: int, dataSize: int, bSize: int):
        self.bucketSize = bSize
        with open(fp, "r", encoding="utf-8") as file:
            self.dataFile = file.read().splitlines()
        self.supp = ((supp/100) * len(self.dataFile))*(dataSize/100)
        self.EOF = int(len(self.dataFile) * (dataSize/100))

    #updates the support value and dataSize for multiple passes
    def setSupportDataSize(self, supp: int, dataSize: int):
        self.supp = ((supp/100) * len(self.dataFile))*(dataSize/100)
        self.EOF = int(len(self.dataFile) * (dataSize/100))

    def pairsHash( pair: tuple, num = 1) -> int:
        if num == 1:
                return (pair[0] + pair[1]) % 50021  
        return (pair[0] + pair[1]) % 50993

    def updateFreq(freqCount: dict, basket: list) -> dict:
        for item in basket:
                if item not in freqCount:
                    freqCount[item] = 1
                else:
                    freqCount[item] += 1
        return freqCount

    def getFreqBasket(freqItems: list, basket: list) -> list:
        freqItems = set(freqItems)
        return [value for value in basket if value in freqItems]

    def updateBucket(self, basket: list, bucket: numpy.ndarray, num = 1):
        pairs = combinations(basket, 2)
        for pair in pairs:
            bucket_num = PCY.pairsHash(pair, num) % self.bucketSize
            if bucket[bucket_num] < self.supp:
                bucket[bucket_num] += 1
        return bucket

    def updateBucketMulti(self, basket: list, buckets: list, num_hashes = 2) -> list:
        for i in range(num_hashes):
            buckets[i] = self.updateBucket(basket, buckets[i], i+1)
        return buckets

    def getBitVector(self, bucket: numpy.ndarray) -> BitVector:
        bitV = BitVector(self.bucketSize)
        for i in range(self.bucketSize):
            if bucket[i] >= self.supp:  # if the bucket count meets the threshold set vector
                bitV.setBit(i)  # set the bit vector to true
        return bitV

    def getVectorMulti(self, buckets: list, num_hashes=2) -> list:
        bitV= []
        for i in range(num_hashes):
            bitV.append(self.getBitVector(buckets[i]))  # for each basket create a bitVector
        return bitV

    def getFreqItems(self, freqCount: dict) -> list:
        freqItems = []
        for item in freqCount.keys():
            if freqCount[item] >= self.supp:
                freqItems.append(item)
        return freqItems

    def setCandidatePairs(self, freqItems: list, bitVector: BitVector, num = 1) -> dict:
        allPairs = combinations(freqItems, 2)
        candidatePairs = {}
        for pair in allPairs:
            if bitVector.getBit(PCY.pairsHash(pair, num) % self.bucketSize):
                candidatePairs[pair] = 0
        return candidatePairs

    def setCandidatePairsMulti(self, freqItems: list, bitVector: list):
        allPairs = combinations(freqItems, 2)
        candidatePairs = {}
        for pair in allPairs:
            inAll = True
            for i in range(len(bitVector)):
                if not bitVector[i].getBit(PCY.pairsHash(pair, i+1) % self.bucketSize):
                    inAll = False
                    break
            if inAll:
                candidatePairs[pair] = 0
        return candidatePairs

    def updateCandidatePairs(candidatePairs, basket):
        pairs = combinations(basket, 2)
        for pair in pairs:
            if pair in candidatePairs:
                candidatePairs[pair] += 1
        return candidatePairs

    #this definiton will print the amount of pairs found
    def printPairs(self, candidatePairs):
        count = set()
        for pair in candidatePairs.keys():
            if candidatePairs[pair] >= self.supp:
                count.add(pair)
        print("Frequent Pairs found: " + str(len(count)))

    #This definition will execute the standard PCY Algorithm
    def PCYNormal(self):
        bucket = numpy.zeros(self.bucketSize, dtype=int)

        # === First Pass ===
        freqCount = {}

        for line in range(self.EOF):
            basket = [int(n) for n in self.dataFile[line].split()]
            freqCount = PCY.updateFreq(freqCount, basket)
            bucket  = self.updateBucket(basket, bucket)

        bitVector = self.getBitVector(bucket)
        del bucket
        freqItems = self.getFreqItems(freqCount)
        del freqCount

        #=== Second Pass ===
        candidatePairs =  self.setCandidatePairs(freqItems, bitVector)
        for line in range(self.EOF):
            basket = [int(n) for n in self.dataFile[line].split()]
            candidatePairs = PCY.updateCandidatePairs(candidatePairs, basket)
        self.printPairs(candidatePairs)

    #This definition wille execute the PCY MultiStage Algorithm
    def PCYMultiStage(self):
        bucket1 = numpy.zeros(self.bucketSize, dtype=int)

        #=== First Pass ===
        freqCount = {}
        for line in range(self.EOF):
            basket = [int(n) for n in self.dataFile[line].split()]
            freqCount = PCY.updateFreq(freqCount, basket)
            bucket1 = self.updateBucket(basket, bucket1)
        bitVector1 = self.getBitVector(bucket1)
        del bucket1
        freqItems = self. getFreqItems(freqCount)
        del freqCount

        #=== Second Pass ===
        bucket2 = numpy.zeros(self.bucketSize, dtype=int)

        for line in range(self.EOF):
            basket = [int(n) for n in self.dataFile[line].split()]
            freqBasket = PCY.getFreqBasket(freqItems, basket)
            bucket2 = self.updateBucket(freqBasket, bucket2, 2)

        bitVector2 = self.getBitVector(bucket2)
        del bucket2

        #=== Third Pass ===
        candidatePairs = self.setCandidatePairsMulti(freqItems, [bitVector1, bitVector2])
        for line in range(self.EOF):
            basket = [int(n) for n in self.dataFile[line].split()]  # split basket into items
            candidatePairs = PCY.updateCandidatePairs(candidatePairs, basket)
        self.printPairs(candidatePairs)

    #This defintion will execute the PCY multi hash algorithm
    def PCYMultiHash(self):
        buckets = [numpy.zeros(self.bucketSize, dtype=int), numpy.zeros(self.bucketSize, dtype=int)]

        #=== First Pass ===
        freqCount = {}
        for line in range(self.EOF):
            basket = [int(n) for n in self.dataFile[line].split()]
            freqCount = PCY.updateFreq(freqCount, basket)
            buckets = self.updateBucketMulti(basket, buckets)

        bitVectors=self.getVectorMulti(buckets)
        del buckets
        freqItems = self.getFreqItems(freqCount)
        del freqCount

        #=== Second Pass ===
        candidatePairs = self.setCandidatePairsMulti(freqItems, bitVectors)
        for line in range(self.EOF):
            basket = [int(n) for n in self.dataFile[line].split()]  # split basket into items
            candidatePairs = PCY.updateCandidatePairs(candidatePairs, basket)
        self.printPairs(candidatePairs)

#used for looping conditions of the algoruthm
sizeList = [1, 5, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
supportList = [1, 5, 10]

def apriori():
    for i in supportList:
        for j in sizeList:
            run = APriori("retail.txt", i, j)
            print(f'APriori with a support of {i}% data size of {j}%')
            run.execute()
            print("\n")
            del run

def PCYNorm():

    for i in supportList:
        for j in sizeList:
            startTime = time.perf_counter()
            run = PCY("retail.txt", i, j, 50000)
            print(f'PCY with a support of {i}% data size of {j}%')
            run.PCYNormal()
            endTime = time.perf_counter()
            runTime = ((endTime - startTime) * 1000)
            print(f'PCY run time: {runTime:.02f} ms')
            print("\n")
            del run


def PCYMultiS():
    for i in supportList:
        for j in sizeList:
            startTime = time.perf_counter()
            run = PCY("retail.txt", i, j, 50000)
            print(f'PCY with a support of {i}% data size of {j}%')
            run.PCYMultiStage()
            endTime = time.perf_counter()
            runTime = ((endTime - startTime) * 1000)
            print(f'PCY run time: {runTime:.02f} ms')
            print("\n")
            del run

def PCYMultiH():
    for i in supportList:
        for j in sizeList:
            startTime = time.perf_counter()
            run = PCY("retail.txt", i, j, 50000)
            print(f'PCY with a support of {i}% data size of {j}%')
            run.PCYMultiHash()
            endTime = time.perf_counter()
            runTime = ((endTime - startTime) * 1000)
            print(f'PCY run time: {runTime:.02f} ms')
            print("\n")
            del run

print("+++ Welcome +++")
print("1. A Priori \n2. PCY(Normal)\n3. PCY MultiStage\n4. PCY MultiHash")
algo = int(input("Which algorithm would you like to run?: "))

if algo == 1:
    apriori()

elif algo == 2:
    PCYNorm()

elif algo == 3:
    PCYMultiS()

elif algo == 4:
    PCYMultiH()

else:
    print("Incorrect option.")
