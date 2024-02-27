makefile_directory=${1:-.}

cd $makefile_directory

make clean fclean && make all

# Définir un tableau de valeurs de test valides
declare -a valid_values=(
"\"1 2 3\" 4 5"
"1 2 3 4 5 6 7"
"0 1 2147483647"
"2147483647"
"\"00000000000001 002 00003\" 4 5"
"\"0000000000000000000000\" \"8 9 \" 4 5"
"-2147483648"
"\"-1 -2 -3 -4 -5\" 6 7"
"\"1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100\" 101 102"
)

# Définir un tableau de valeurs de test invalides
declare -a invalid_values=(
"2147483648"
"-2147483649"
"1.5 2.5"
"\"1.5 2.5\" 5 8 1"
"\"4=-\" 5 8 1"
"\"1+2\" 3 4 5"
"\"10000+2\" 3 4 5"

"1+2"
"1,2,3"
" "
"abc123"
"     "
"--5"
"++0"
"+-1"
"1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100+101"
)

echo -ne "TEST DIR[$makefile_directory] \n"
# Itérer sur le tableau de valeurs de test valides
count=0
results=""
for i in "${valid_values[@]}"
do
   ((count++))
   echo -ne "\r[${count}/${#valid_values[@]}]"
   # Exécuter le programme push_swap avec la valeur de test actuelle et vérifier le code de sortie
   if eval ./push_swap $i > /dev/null 2>&1; then
    results="${results}\033[0;32m[OK]\033[0m"
    else
        results="${results}\033[0;31m[Erreur]\033[0m"
    fi
done
echo -e "${results}"

# Itérer sur le tableau de valeurs de test invalides
count=0
results=""
echo -ne "\n[INVALID VALUES]\n"
for i in "${invalid_values[@]}"
do
   ((count++))
   echo -ne "\r[${count}/${#invalid_values[@]}]"
   # Exécuter le programme push_swap avec la valeur de test actuelle et vérifier le code de sortie
   if ! eval ./push_swap $i > /dev/null 2>&1; then
    results="${results}\033[0;32m[OK]\033[0m"
    else
        results="${results}\033[0;31m[Erreur]\033[0m"
    fi
done
echo -e "${results}"

echo ""