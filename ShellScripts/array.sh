# ┌────────────────────────────────────────────────┐
# │                     Declare                    │
# └────────────────────────────────────────────────┘

# ============== indirect declaration ==============
array_a[0]=1
array_a[1]=2
array_a[2]=3

echo ${array_a[0]}

# ============== explicit declaration ==============
declare -a array_b

array_b[0]='han'
array_b[1]="marc"
array_b[2]="fuck the world"

echo ${array_b[2]}

# =============== compound assignment ==============
array_c=(10 20 30 40 50 60 70 80 90 100)
echo ${array_c[1]}

# ┌────────────────────────────────────────────────┐
# │                      Print                     │
# └────────────────────────────────────────────────┘

echo print all elements:
echo ${array_a[@]}
echo ${array_b[*]}
echo ${array_a[@]:0}
echo ${array_b[*]:0}

echo print first element:
echo ${array_a[0]}
echo ${array_c}

echo print particular element:
echo ${array_c[7]}

echo print from a particular index:
echo ${array_c[@]:3}

echo print in range:
echo ${array_c[@]:3:5}

echo size of an array:
echo ${#array_c[@]}
echo ${#array_a[*]}

echo length of particular element:
echo ${#array_b}
echo ${#array_b[1]}
echo ${#array_b[2]}

