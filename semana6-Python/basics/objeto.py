#!/usr/bin/env python3

# nome de classe sempre capitalizado
class Estudante():
    # método construtor
    def __init__(self, nome, id):
        self.nome = nome
        self.id = id

    def exibe_aluno(self):
        print(f"{self.nome} : {self.id}")

    def muda_id(self, id):
        self.id = id

def main():
    aluno = Estudante("Téo", 78)
    aluno.exibe_aluno()
    aluno.muda_id(123)
    aluno.exibe_aluno()

if __name__ == "__main__":
    main()