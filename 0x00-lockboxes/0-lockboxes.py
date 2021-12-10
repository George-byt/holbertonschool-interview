#!/usr/bin/python3


def canUnlockAll(boxes):
    if not boxes:
        return False
    if len(boxes) == 0:
        return False
    keys = []
    keys.append(0)
    for key in keys:
        new_keys = boxes[key]
        for new_key in new_keys:
            if new_key not in keys and new_key < len(boxes):
                keys.append(new_key)
    if len(keys) == len(boxes):
        return True
    return False
