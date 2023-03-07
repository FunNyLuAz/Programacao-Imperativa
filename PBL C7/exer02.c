int calcular_hash(char* texto, int modulo);

int main() {

      char* texto = "Lorem ipsum dolor sit amet.";

      printf("\n%d\n", calcular_hash(texto, 1000000));

      return 0;
}

int calcular_hash(char* texto, int modulo) {
      // Calcula o hash para um determinado texto
      int hash = 0;
      
      while (*texto != '\0') {
            hash += *texto;
            texto++;
      }

      hash = hash % modulo;

      return hash;
}
