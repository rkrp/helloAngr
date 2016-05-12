#!/usr/bin/env python

import angr

p = angr.Project('helloAngr')

argv1 = angr.claripy.BVS("argv1", 10*8)
initial_state = p.factory.entry_state(args=["helloAngr", argv1])

for byte in argv1.chop(8):
	initial_state.add_constraints(byte >= 0x41)
	initial_state.add_constraints(byte <= 0x5A)

initial_state.add_constraints(argv1.chop(8)[0] ^ argv1.chop(8)[1]== 0x1F)
initial_state.add_constraints(argv1.chop(8)[0] == 0x4F)

pg = p.factory.path_group(initial_state)
pg.explore(find=0x8048575, avoid=0x804853F)

found = pg.found[0]

solution = found.state.se.any_str(argv1)

print solution
