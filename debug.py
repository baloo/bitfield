import sys

value = sys.stdin.buffer.read()
print(["{:08b}".format(byte) for byte in value])
