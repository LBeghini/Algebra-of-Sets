# Trabalho 1 - Álgebra de Conjuntos

**Questão 1:**

Construa um sistema com as seguintes características.
1. Entrada de dados lida em um arquivo texto.
2. As linhas do arquivo podem conter as seguintes informações:
- Um ou mais conjuntos.
- Um ou mais elementos.
3. Formato das linhas:
- Conjunto:
  - Uma única letra maiúscula, o sinal de igual, abertura de chave, n elementos separados por vírgula (n ≥ 0),
fechamento da chave.
  - Exemplo: A = {1, 87, 4, −1, 43}
- Elemento:
  - Uma única letra minúscula, o sinal de igualdade, um valor.
  - Exemplo: b = 87
- Elementos são sempre números inteiros.
4. Um menu que apresenta e verifica ou calcula as seguintes operações:
- Pertence (∈)
- Não pertence (∈/)
- Contido ou igual (⊆)
- Não contido ou igual (*)
- Contido propriamente (⊂)
- Não contido propriamente (6⊂)
- União (S)
- Interseção (T)
- Produto cartesiano (×)
- Conjunto das partes (P(A))
- Diferença de conjuntos
5. Observar os operandos necessários e suficientes para cada operação. Se faltarem operandos, informar erro. Se
sobrarem, use os primeiros que figurarem no arquivo de entrada e ignore os demais.
6. Se possível, use todos os operandos que constarem no arquivo de entrada.
7. Exemplos:
- ∈ e ∈/: usar a primeira ocorrência de conjunto e a primeira de elemento. Despreze os demais.
- S e T : use todas as ocorrências de conjuntos e ignore os elementos.
- Produto cartesiano: utilize as duas primeiras ocorrências de conjuntos.
- Conjunto das partes: use a primeira ocorrência de conjunto.
8. As saídas podem ser para tela ou para arquivo.
9. As opções do menu são operações elementares. **Sempre que possível**, utilize-as em computações mais complexas.
Em outras palavras, crie funções ou métodos para implementá-las e reutilize em lugar de repetir trechos de códigos
ou raciocínios em outros lugares do sistema. Por exemplo, use ∈ ou ∈/ para verificar ⊂.
10. Sempre que a operação for reversível, ao final da execução da operação, pergunte se o usuário quer reverter (achar os
operandos originais). Se o usuário escolher ***sim***, reverta (encontre os operando iniciais). **Importante:** não pegue
os operandos iniciais em algum objeto ou nos dados de entrada. Execute a operação inversa!

**Questão 2:**

Utilizando apenas o sistema desenvolvido, resolva os seguintes problemas:

1. Os times 4, 8, 12 e 16 do estado de Pernambuco devem jogar com os times 3, 7, 11 e 15 do estado do Pará. Cada
time de Pernambuco deve jogar uma vez com cada time do Pará. Exiba os jogos que devem ser realizados.
2. Suponha que você tem o código (numérico) dos alunos que obtiveram média na disciplina **A**, o código dos alunos
com média na disciplina **B** e o código dos alunos com média na disciplina **C**. O critério de aprovação na escola exige
média em todas as disciplinas para aprovação. Exiba a lista dos alunos aprovados. Exiba a lista dos alunos com
média em pelo menos uma disciplina.
3. Uma empresa tem a seguinte política de premiação de fim de ano: ganha prêmio o funcionário que tiver batido sua
meta no primeiro ou no segundo semestre ou em ambos e que tenha sido o melhor vendedor em pelo menos um mês.
De posse do código do funcionário, da relação de funcionários cumpridores da meta em cada semestre e da relação
de melhores vendedores do mês, informe se este funcionário receberá ou não prêmio de fim de ano.
4. Considere uma sala de aula com x alunos (identificados pelos números de matrícula *n* ∈ N). Considere que
alguns alunos da turma estão cursando Matemática Discreta. Encontre e exiba os alunos que não estão cursando
matemática discreta.
