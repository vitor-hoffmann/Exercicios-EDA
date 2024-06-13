// Esta fun��o rearranja o vetor v[0..n-1] em ordem crescente.
//Ref.: https://www.ime.usp.br/~pf/algoritmos/aulas/ordena.html

long insertion(int n, int v[])
{
   int op = 0;
   for (int j = 1; j < n; ++j) {
      int x = v[j];
	  op+=4;
      int i;
      for (i = j-1; i >= 0 && v[i] > x; --i){ 
         v[i+1] = v[i];
		 op+=5;
	  }
	  op++;
      v[i+1] = x;
   }
   return op;
}


// Bubble sort algorithm.
// Ref.: https://github.com/kayelserafim/bubble-sort-mpi/blob/main/src/parallel_master.c

long bubble(int n, int *vetor) {
	int c = 0, d, troca, trocou = 1, op = 0;
	while ((c < (n - 1)) & trocou) {
		trocou = 0;
		op += 3;
		for (d = 0; d < n - c - 1; d++){
			op += 3;
			if (vetor[d] > vetor[d + 1]) {
				troca = vetor[d];
				vetor[d] = vetor[d + 1];
				vetor[d + 1] = troca;
				trocou = 1;
				op += 5;
			}
		}
		c++;
	}
	return op;
}