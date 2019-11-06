
def simpleTextEditor(operations):
    S = ""
    operationStack = list()

    for op in operations:
        # print(operationStack)
        if op[0] == 1:
            #append operation
            S = S + op[1]
            operationStack.append(op)
        elif op[0] == 2:
            # delete operation
            toBeDeleted = S[len(S) - int(op[1]):]
            S = S[:len(S) - int(op[1])]
            operationStack.append([*op, toBeDeleted])
        elif op[0] == 3:
            # print operation
            print(S[int(op[1]) - 1])

        elif op[0] == 4:
            # undo operation    
            if operationStack:
                undoOperation = operationStack.pop()

                if undoOperation[0] == 1:
                    S = S[:len(S) - len(undoOperation[1])]
                elif undoOperation[0] == 2:
                    S = S + undoOperation[2]

if __name__ == "__main__":
    Q = int(input())
    operations = list()
    for _ in range(Q):
        op = input().split()
        op[0] = int(op[0])
        operations.append(op)

    simpleTextEditor(operations)