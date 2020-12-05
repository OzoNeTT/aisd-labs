class MatrixFibonacci:
    Q = [[1, 1],
         [1, 0]]

    def __init__(self):
        self.savedMatrix = {}

    def matrixPermutate(self, M1, M2):
        a1 = M1[0][0] * M2[0][0] + M1[0][1] * M2[1][0]
        a2 = M1[0][0] * M2[0][1] + M1[0][1] * M2[1][1]
        a3 = M1[1][0] * M2[0][0] + M1[1][1] * M2[1][0]
        a4 = M1[1][0] * M2[0][1] + M1[1][1] * M2[1][1]
        permMat = [[a1, a2], [a3, a4]]
        return permMat

    def fastPower(self, M, p): 
        if p == 1:
            return M
        if p in self.savedMatrix:
            return self.savedMatrix[p]

        mat = self.fastPower(M, p // 2)
        matQd = self.matrixPermutate(mat, mat)
        self.savedMatrix[p] = matQd

        return matQd

    def get_number(self, n):
        if n == 0 or n == 1:
            return 1
        if n < 0:
            print("Error 404")
            return  
        Pn = []
        while n != 0:
            Pn.append(n & -n)
            n = n & (n - 1)
        matx = [self.fastPower(MatrixFibonacci.Q, power) for power in Pn]
        while (len(matx) > 1):
            M1 = matx.pop()
            M2 = matx.pop()
            permMat = self.matrixPermutate(M1, M2)
            matx.append(permMat)
        return matx[0][0][0]


mfib = MatrixFibonacci()
n = int(input())
num = mfib.get_number(n - 1)

print(num)