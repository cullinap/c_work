import argparse,sys


def main(*args):

    args = [arg for arg in args]

    for i,arg in enumerate(args):
        print(f'arg {i+1}: {arg}')

    states = ['California', 'Oregon', 'Washington', 'Texas']

    for i,state in enumerate(states):
        print(f'state {i}: {state}')


if __name__ == '__main__':
    main(*sys.argv[1:])