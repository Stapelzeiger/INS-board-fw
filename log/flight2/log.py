import csv
import matplotlib.pyplot as plt
import sys

f = open(sys.argv[1], 'r')
csv_reader = csv.reader(f)
# data = [row for row in csv_reader]
data = list(csv_reader)

fig = plt.figure()
ax = fig.add_subplot(111, axisbg = 'w')
ax.plot(data[1:])
ax.legend(data[0])
plt.show()