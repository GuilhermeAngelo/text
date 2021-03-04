#include <string.h>

int validaCPF(char cpf[]) {
  int tam, soma, d1, d2;
  int cpfInt[11];

  tam = strlen(cpf);
  if (tam != 11) {
    return 0;
  }
  for (int i = 0; i < 11; i++) {
    if (cpf[i] < '0' || cpf[i] > '9') {
      return 0;
    }
  }
  for (int i = 0; i < 11; i++) {
    cpfInt[i] = cpf[i] - '0';
  }

  soma = 0;
  for (int i = 0; i < 9; i++) {
    soma += cpfInt[i] * (10 - i);
  }
  d1 = 11 - (soma % 11);
  if (d1 == 10 || d1 == 11) {
    d1 = 0;
  }
  if (cpfInt[9] != d1) {
    return 0;
  }

  soma = 0;
  for (int i = 0; i < 10; i++) {
    soma += cpfInt[i] * (11 - i);
  }
  d2 = 11 - (soma % 11);
  if (d2 == 10 || d2 == 11) {
    d2 = 0;
  }
  if (cpfInt[10] != d2) {
    return 0;
  }
  
  return 1;
}