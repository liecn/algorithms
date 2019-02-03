# coding=utf-8 #
import numpy as np
para = int(input("请输入："))
start_list=np.arange(para)
middle_list=np.zeros([para])
end_list=np.zeros([para])
rank=0
i=0
while(rank < start_list.size):
    if(rank%2):
        start_list = np.append(start_list, start_list[rank])
    else:
        middle_list[i] = start_list[rank]
        i = i + 1
    rank=rank+1
for i in range(para):
    flag=int(middle_list[i])
    end_list[flag]=i

print(end_list)
#test
# rank=0
# i=0
# while(rank < end_list.size):
#     if(rank%2):
#         end_list = np.append(end_list, end_list[rank])
#     else:
#         middle_list[i] = end_list[rank]
#         i = i + 1
#     rank=rank+1
# print(middle_list)

