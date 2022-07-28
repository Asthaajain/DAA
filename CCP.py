import sys


# Function to find the minimum number of coins required
# to get a total of `target` from set `S`
def findMinCoins(S, target):

	# if the total is 0, no coins are needed
	if target == 0:
		return 0

	# return infinity if total becomes negative
	if target < 0:
		return sys.maxsize

	# initialize the minimum number of coins needed to infinity
	coins = sys.maxsize

	# do for each coin
	for c in S:

		# recur to see if total can be reached by including current coin `c`
		result = findMinCoins(S, target - c)

		# update the minimum number of coins needed if choosing the current
		# coin resulted in a solution
		if result != sys.maxsize:
			coins = min(coins, result + 1)

	# return the minimum number of coins needed
	return coins


if __name__ == '__main__':

	# coins of given denominations
	S = [1, 3, 5, 7]

	# total change required
	target = 18

	coins = findMinCoins(S, target)
	if coins != sys.maxsize:
		print('The minimum number of coins required to get the desired change is',
			coins)
