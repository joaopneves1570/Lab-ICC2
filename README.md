# Projeto 1 – Lab ICC2  
**SCC0220 - Laboratório de Introdução à Ciência da Computação II**  
Prof. Jean R. Ponciano – ICMC/USP  

---

## 📌 Descrição
Este repositório contém a implementação do **Entregável 01 – Palíndromos** da disciplina **SCC0220 - Laboratório de ICC II**.  
O objetivo é desenvolver três versões em C de um programa que verifica se uma string é um palíndromo, considerando apenas caracteres alfanuméricos e ignorando diferenças entre maiúsculas e minúsculas.  

Um **palíndromo** é uma sequência que pode ser lida da mesma forma da esquerda para a direita e vice-versa, como por exemplo:  
- `asa`  
- `socorram-me, subi no onibus em Marrocos`  

---

## 📂 Estrutura do Repositório
- `palindromo_iterativo.c` → Versão **iterativa** implementada manualmente.  
- `palindromo_ia.c` → Versão **iterativa gerada por IA**.  
- `palindromo_recursivo.c` → Versão **recursiva** implementada manualmente.  
- `README.md` → Este arquivo.  
- `a.exe` → Executável gerado em ambiente local (Windows).  

---

## ⚙️ Especificações
- O programa deve ler repetidamente **linhas de texto** até o fim da entrada (EOF).  
- Para cada linha, imprimir:  
  - `"Sim"` → se a string for palíndromo.  
  - `"Não"` → caso contrário.  
- Apenas caracteres alfanuméricos são considerados (ignorar espaços, vírgulas, pontos, acentos e outros símbolos).  
- Não há distinção entre letras maiúsculas e minúsculas.  
- A string vazia e strings de apenas um caractere são consideradas palíndromos.  

---

## 📥 Exemplos de Entrada e Saída
**Entrada:**
ICMC
Rir, o breve verbo rir
ab12ba
ab1ba
Luz azul
1551
a

**Saída:**
Não
Sim
Não
Sim
Sim
Sim
Sim
