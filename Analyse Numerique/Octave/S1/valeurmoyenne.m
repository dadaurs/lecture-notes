function vm = valeurmoyenne(v)
sum=0
nbels=0
for i = v
	sum+=i
nbels++
end
vm = sum/nbels
end
