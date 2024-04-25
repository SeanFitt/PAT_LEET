import random

def selectSort(list):
    for i in range(len(list)):
        min_index=i
        for j in range(i, len(list)):
            if list[j]<list[min_index]:
                min_index=j
        tmp=list[min_index]
        list[min_index]=list[i]
        list[i]=tmp

if __name__=='__main__':
    n=10
    test_list=[]
    for i in range(n):
        test_list.append(random.randint(0,10))
    print(test_list)
    selectSort(test_list)
    print(test_list)