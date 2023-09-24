typedef struct nodo{
int dato;
struct nodo *sgte;
}cola;
void encola(cola **, cola **, int);
int desencola(cola **, cola **);
void vaciaCola(cola **);
int ntamao(cola *);
int estaVacia(cola **);
int frente();
int opcion, a, b, c;
