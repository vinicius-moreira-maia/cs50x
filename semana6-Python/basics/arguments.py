import sys

if len(sys.argv) != 2:
    print("faltam argumentos")
    sys.exit(1)

print(f"{sys.argv[1]}")
sys.exit(0) 