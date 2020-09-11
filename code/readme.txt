Crec convenient comentar un seguit d'aspectes sobre la pràctica:

- Vaig decidir crear una classe anomenada "Visibilitats" perquè no trobava un bon disseny el fet d'emplenar Solucio amb mètodes privats per comprovar vistes, encara que hagués sigut una opció. 
- També cal dir que, per tal de facilitar la comprensió, vaig preferir diferenciar la funció "filaNord" (el mateix per "colOest") de "finalFilaNord", tot i que es podria haver fet en una única funció.
- Per trobar la millor solució vaig prendre com a referència el problema de la Motxilla vist a teoria. Per tant, l'ideal hagués sigut crear una matriu amb les altures màximes disponibles sense repetir-se a la mateixa fila ni columna al constructor de Solucio. Això tenia pinta a un altre backtracking. No obstant això, no trobava lògic fer un backtracking per justament intentar reduir el cost d'un altre backtracking. Per tant, com ho he plantejat, la matriu d'accumulacions intenta emplenar la mateixa fila sense repetir elements. Ara bé, si abans d'arribar al final de la fila ja els ha usat tots llavors torna a començar. En definitiva el cost d'aquesta acció és O(n^2). No poda tant com si fos la matriu perfecta però ajuda molt.

Fitxer:
4
1 3 2 3
4 2 2 1
3 2 2 1
1 2 2 3
6
4 4 4 4 1 2

Matriu per la millor solució (posteriorment es fan les accumulacions):
1 2 3 4
1 2 3 4
2 3 4 6
3 4 5 6

