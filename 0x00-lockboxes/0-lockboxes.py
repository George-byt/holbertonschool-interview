#!/usr/bin/python3
'''
Lockbox task: You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1
and each box may contain keys to the other boxes
'''


# asdfasdfasfasdfsd
def canUnlockAll(boxes):
    '''true if it can unlock al box from 0'''
    keys = set(boxes[0])
    tmp = {0}
    counter = 0

    # print("boxes: ", boxes)
    while (counter != len(tmp)):
        counter = len(tmp)
        for key in keys:
            try:
                tmp.update(boxes[key])
            except Exception:
                continue
        keys.update(tmp)

    # print(keys)
    for i in range(len(boxes)):
        if i not in keys:
            return False

    return True
