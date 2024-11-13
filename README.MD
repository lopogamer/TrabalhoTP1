# Formatação de Código com AStyle

Para formatar o código:

1. **Instale o AStyle**: [AStyle](https://astyle.sourceforge.net/).

2. **Navegue até a pasta `~/Exemplo`.**

3. **Rode o seguinte comando:**

    ```bash
    astyle --style=kr --pad-oper --max-code-length=120 --remove-brackets --align-pointer=type --align-reference=type --break-after-logical --keep-one-line-blocks src/*.cpp include/*.h
    ```

# Compilar e Rodar o Código

1. **Instale o Make**: Você pode baixar o Make para Windows [aqui](https://sourceforge.net/projects/gnuwin32/).

2. **Adicione o Make ao PATH**:
   - Encontre o executável `make.exe` ou `mingw32-make.exe` (por exemplo, em `C:\Program Files (x86)\GnuWin32\bin` ou `C:\MinGW\bin`).
   - Copie o caminho.
   - Vá em **Configurações do Sistema** > **Sistema** > **Configurações Avançadas do Sistema** > **Variáveis de Ambiente**.
   - Na variável `Path` em **Variáveis de Sistema**, clique em **Editar** e adicione o caminho.

3. **Navegue até a pasta do projeto**:
   - Abra o terminal e vá até o diretório do projeto. Por exemplo:
     ```bash
     cd ~/Exemplo
     ```

4. **Compile e rode o programa**:
   - No terminal, execute o comando:
     ```bash
     make
     ```
   - Para executar o programa compilado, use:
     ```bash
     ./Trabalho
     ```

Essas instruções ajudam a formatar, compilar e rodar o código no Windows usando AStyle e Make.

