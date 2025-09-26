# Instruções para Utilizar as Aulas de Fundamentos de Programação em C/C++

Este documento descreve três níveis de preferência para configurar e executar nas aulas de Fundamentos de Programação em C/C++. Cada nível inclui etapas de utilização, prós e contras. Escolha o nível que melhor se adapta ao seu ambiente e conhecimentos.

## Nível 1: Ferramentas 100% Online
Ideal para quem quer começar rapidamente sem instalar nada localmente. Use compiladores online ou IDEs baseados na web.

### Exemplos de Ferramentas
- [Programiz C/C++ Online Compiler](https://www.programiz.com/cpp-programming/online-compiler/): Compilador simples para C/C++ com editor integrado.
- [CS50.dev](https://cs50.dev/): IDE completo online da Harvard CS50, com suporte a C/C++, terminal integrado e colaboração.

### Etapas de Utilização
1. Acesse o site da ferramenta escolhida (ex.: https://cs50.dev/).
2. Crie uma conta gratuita se necessário.
3. Copie o código das aulas (ex.: arquivos `.c` ou `.cpp` do workspace) para o editor online.
4. Compile e execute o código diretamente no navegador.
5. Para salvar progresso, use a funcionalidade de download/upload de arquivos da ferramenta.

### Prós
- Sem instalação necessária; funciona em qualquer dispositivo com navegador.
- Acesso rápido e gratuito para testes iniciais.
- Suporte a múltiplas linguagens e bibliotecas básicas.

### Contras
- Dependente de conexão à internet.
- Limitações em recursos avançados (ex.: depuração limitada, sem acesso a arquivos locais).
- Não ideal para projetos grandes ou integração com sistemas locais.

## Nível 2: Usar um IDE
Para usuários que preferem um ambiente de desenvolvimento local mais robusto, com instalação simples.

### Exemplos de IDEs
- [Visual Studio Code (VS Code)](https://code.visualstudio.com/docs/languages/cpp): Gratuito, extensível, com suporte nativo a C/C++ via extensões.
- [Code::Blocks](https://www.codeblocks.org/): IDE gratuito focado em C/C++, com compilador integrado.

### Etapas de Utilização (Exemplo com VS Code)
1. Baixe e instale o VS Code do site oficial.
2. Instale a extensão "C/C++" da Microsoft (pesquise no marketplace do VS Code).
3. Abra o workspace (`/workspaces/FundamentosC_Cpp`) no VS Code.
4. Para compilar: Use o terminal integrado (Ctrl+`) e execute `gcc arquivo.c -o executavel` ou `g++ arquivo.cpp -o executavel`.
5. Execute com `./executavel`.
6. Para depuração: Configure um `launch.json` via a aba "Run and Debug".

### Prós
- Ambiente completo e personalizável com extensões.
- Suporte a depuração avançada, controle de versão (Git) e integração com ferramentas locais.
- Melhor para aprendizado progressivo e projetos maiores.

### Contras
- Requer instalação e configuração inicial (pode ser complexo para iniciantes).
- Dependente de recursos do sistema local (ex.: espaço em disco, compatibilidade).
- Menos portabilidade entre dispositivos.

## Nível 3: Utilizando Dev Container (Dentro do VS Code, com Docker)
Para um ambiente isolado e consistente, usando containers Docker dentro do VS Code.

### Etapas de Utilização
1. Instale o Docker no seu sistema (se não tiver).
2. Instale o VS Code e a extensão "Dev Containers".
3. Abra o workspace no VS Code; ele detectará automaticamente o dev container configurado (baseado em Debian GNU/Linux 12).
4. Reabra o workspace no container (VS Code pedirá para "Reopen in Container").
5. Use as ferramentas pré-instaladas: `gcc`, `g++`, `make`, `cmake`, etc., no terminal integrado.
6. Compile e execute código como no Nível 2 (ex.: `make main` no diretório `aula01`).
7. Para depuração: Use `gdb` ou `lldb` no terminal, ou configure no VS Code.

### Vídeo Tutorial
Assista a este vídeo para ver as etapas em ação: 
- [How to: Development Containers](https://www.youtube.com/watch?v=-0QLIodwRlk)


### Prós
- Ambiente isolado e consistente (mesmo em diferentes máquinas), com ferramentas pré-configuradas (gcc, make, valgrind, etc.).
- Integração perfeita com VS Code; evita conflitos com o sistema host.
- Ideal para colaboração e reprodução exata do ambiente de desenvolvimento.

### Contras
- Requer instalação do Docker (pode ser pesado em recursos).
- Curva de aprendizado para containers; dependente de Docker rodando.
- Menos flexível para customizações fora do container.

Escolha o nível com base na sua comodidade. Para dúvidas, consulte a documentação das ferramentas ou o repositório do projeto.