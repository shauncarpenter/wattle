t = {}

for val=1,1000000 do
   t[val] = val*100
end

for val=1,1000000 do
   local a = t[val..val]
end
