[N, P] = map(int, input().split(" "))              # N: number of colors/people; P: id of current person
possible_colors = input().split(" ")               # All possible colors
view = [c for c in input().split(" ") if c != ""]  # Hat colors this person sees (if there's only one player, we may see nothing!)
sum=0
for i in range(N-1):
    sum+=(possible_colors.index(view[i]))
print (possible_colors[(P+N-sum%N)%N])