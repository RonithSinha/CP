for t in range(int(input())):
    N,K = map(int,input().split())
    arr = list(map(int,input().split()))
    ll = sorted([(v,i) for i,v in enumerate(arr)])
    p = 1
    print('arr: ',arr)
    print('ll: ',ll)
    for i in range(1,len(ll)):
        if ll[i][1] != ll[i-1][1] + 1:
            p += 1
    print('Yes' if p <= K else 'No')