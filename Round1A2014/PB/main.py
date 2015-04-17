#!/usr/bin/env python
from collections import deque


def main():
	f = open('input.txt', 'r')

	total_T = int(f.readline())

	for T in xrange(1,total_T+1):
		N = int(f.readline().rstrip('\n'))
		Nodes = {}

		for x in xrange(N-1):
			id1, id2 = map(int, f.readline().rstrip('\n').split())
			n1 = Nodes.get(id1, Node(id1, Nodes))
			n2 = Nodes.get(id2, Node(id2, Nodes))
			link(n1, n2)
			Nodes[id1] = n1
			Nodes[id2] = n2

		# print Nodes
		# print Nodes[1]
		# print Nodes[1].parent()
		# print Nodes[1].children()
		# Nodes[1].parent_id = 3
		# print Nodes[1].parent()
		# print Nodes[1].children()
		# Nodes[1].clean()
		c = N
		for x in xrange(1, N+1):
			clean(Nodes)
			root = Nodes[x]
			form(root)
			

			c = min(resolve(root), c)

		print 'Case #{}: {}'.format(T, c)

def resolve(root):
	# Return the cost of deleting the node to form full bin tree
	children = root.children()
	if children == []:
		return 0
	if len(children) == 1:
		deleted(children[0])
		return children[0].cost
	if len(children) == 2:
		return resolve(children[0]) + resolve(children[1])

	# more than 2 nodes
	children = sorted(children, key=lambda x:-x.cost)
	keep_nodes = children[:2]
	deleted_nodes = children[2:]

	for node in deleted_nodes:
		deleted(node)

	return resolve(keep_nodes[0]) + resolve(keep_nodes[1]) + sum(x.cost for x in deleted_nodes)

def clean(Nodes):
	for node in Nodes.itervalues():
		node.clean()

def form(root):
	root.cost = 1
	for child in root.children():
		child.parent_id = root.id
		form(child)
		root.cost += child.cost 

def deleted(root):
	for child in root.children():
		child.deleted = True
		deleted(child)



class Node(object):
	def __init__(self, id, Nodes):
		self.Nodes = Nodes
		self.id = id
		self.ids = set()
		self.parent_id = None
		self.deleted = False
		self.cost = 0

	def clean(self):
		self.parent_id = None
		self.deleted = False
		self.cost = 0

	def children(self):
		return [self.Nodes[x] for x in self.ids if x != self.parent_id]

	def parent(self):
		return self.Nodes.get(self.parent_id)

	def __repr__(self):
		return "Node(id={}, cost={}, ids={})".format(self.id, self.cost, self.ids)

def link(node1, node2):
	node1.ids |= set([node2.id])
	node2.ids |= set([node1.id])
		


if __name__ == '__main__':
	main()