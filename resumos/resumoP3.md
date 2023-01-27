# ESTRUTURA DE ARMAZENAMENTO EM MASSA

Grande parte dos dispositivos de armazenamento secundário é composta por: 
* Discos magnéticos
	 A velocidade do disco tem duas partes. A taxa de transferência, que é a taxa de fluxo de dados entre o drive e o computador. O tempo de posicionamento(random-access time), que consistem, também em duas partes: (1) O tempo necessário para acessar o cilindro do setor desejado(seek time); (2) O tempo necessário para o setor desejado rotacionar até a cabeça do disco(rotational latency).

* Discos de estado sólido 
	Podem ser mais confiáveis e rápidos que HDs, pois não tempo partes móveis nem seek time e rotational latency. Além de que consomem menos energia. No entanto, possuem um preço mais alto por MB.  	
		
* Fitas magnéticas 
	São relativamente permanentes e podem armazenar grandes quantidades de dados, no entanto o tempo de acesso é menor que o do HD(em cerca de 1000x). Portanto, não são muito úteis como armazenamento secundário.

Os drives de disco modernos são estruturados como grandes arrays unidimensionais de blocos de disco lógicos, que são mapeados pelo SO começando no setor 0 da primeira trilha no cilindro mais externo, depois o procedimento se repete através das trilhas do cilindro, depois pelo resto dos cilindros, do mais externo para o mais interno. Os discos podem ser anexados a um sistema de computação de duas maneiras:
1. através das portas de I/O locais no computador hospedeiro ou 
2. por meio de uma conexão de rede.

As solicitações de I/O de disco são geradas pelo SO, processos de sistema ou processos de usuário. Cada solicitação especifica o endereço a ser referênciado no disco, número de setores a senrem transfiridos, endereço de memória. Os algoritmos de scheduling de disco podem melhorar a largura de banda efetiva, o tempo de resposta médio e a variância no tempo de resposta(minimizar o seek time). Algoritmos: 
* SSTF -> É comum e tem uma abordagem natural. Escolha boa para algoritmo padrão
* SCAN -> Produz menos starvation
* C-SCAN
* LOOK -> Escolha boa para algoritmo padrão
* C-LOOK

Esses algoritmos foram projetados para implementar essas melhorias por meio de estratégias de ordenação das filas de disco. O desempenho dos algoritmos de scheduling de disco pode variar muito em discos magnéticos. Por outro lado, já que os discos de estado sólido não têm partes móveis, o desempenho varia pouco entre os algoritmos, e com muita frequência uma simples estratégia FCFS é utilizada.

O desempenho pode ser prejudicado pela fragmentação externa. Alguns sistemas têm utilitários que varrem o sistema de arquivos para identificar arquivos fragmentados; em seguida, eles mudam blocos de
lugar para diminuir a fragmentação. A desfragmentação de um sistema de arquivos muito fragmentado pode melhorar significativamente o desempenho, mas o sistema pode ter o desempenho reduzido enquanto a desfragmentação está ocorrendo. Sistemas de arquivos sofisticados incorporam muitas estratégias para o controle da fragmentação durante a alocação de espaço de modo que a reorganização do disco não seja necessária. 

O sistema operacional gerencia os blocos do disco. Primeiro, o disco deve ser formatado em baixo nível para a criação dos setores no hardware bruto. Em seguida, o disco é particionado, sistemas de arquivos são criados(agrupa os blocos em clusters- I/O do disco é feito em blocos e I/O de arquivos é feito em clusters) e blocos de inicialização são alocados para armazenar o programa bootstrap do sistema. Finalmente, quando um bloco é corrompido, o sistema deve ter uma forma de submetê-lo a um lock ou de substituí-lo logicamente por um reserva. Já que um espaço de permuta eficiente é essencial a um bom desempenho, os sistemas usualmente ignoram o sistema de arquivos e usam o acesso ao disco bruto na paginação de I/O. Alguns sistemas dedicam uma partição de disco bruta para o espaço de permuta, e outros usam um arquivo dentro do sistema de arquivos. Outros sistemas permitem que o usuário ou o administrador do sistema tomem a decisão fornecendo as duas opções.

Em razão do espaço de armazenamento requerido em sistemas grandes, a redundância dos discos é introduzida por meio de algoritmos RAID. Esses algoritmos permitem que mais de um disco seja usado em determinada operação e permitem a operação continuada e até mesmo a recuperação automática em caso de uma falha no disco. Isso aumenta a confiabilidada e taxa de transferência de dados. Os algoritmos RAID são organizados em diferentes níveis; cada nível fornece alguma combinação de confiabilidade e altas taxas de transferência.
Nível 0: refere-se a arrays de discos com distribuição no nível de blocos, mas sem nenhuma redundância (como o espelhamento ou bits de paridade)
Nível 1: refere-se ao espelhamento de discos
Nível 0+1 e 1+0: o 0+1 refere-se a uma combinação dos níveis 0 e 1. O nível 0 fornece o desempenho, enquanto o nível 1 fornece a comfiabilidade(também é caro), nele um conjunto de discos é distribuido, e a distribuição é espelhada em outra distribuição equivalente. O 1+0 os discos são espelhados em pares e, então, os pares espelhados resultanes são distribuídos.

Diferenças entre 0+1 e 1+0: Se um disco falha no RAID 0+1, uma distribuição inteira fica inacessível, deixando apenas a outra distribuição disponível Se um disco no RAID 1+0, apenas um disco fica indisponível, mas o disco que o espelha continua disponível, assim como os outros discos.

# INTERFACE DO SISTEMA DE ARQUIVOS

Um arquivo é um tipo de dado abstrato definido e implementado pelo SO. É uma sequência de registros lógicos. Um registro lógico podem representar programas e dados. Os arquivos de dados podem ser numéricos, alfabéticos, alfanuméricos ou binários. De modo geral, é um sequência de bits, bytes, linhas ou registros, cujo significado é definido pelo usuário do arquivo.
Arquivos podem ter estruruas diferentes e os tipos de arquivo podem ser usados para indicar essa estrutura. Com isso o SO consegue ler o arquivo da forma desejada, no entanto isso pode tornar o SO muito pesado, pois precisa conter código para dar suporte ao diferentes tipo de estrutura de arquivo. Um arquivo pode ser considerado uma sequencia de blocos. Todas as funões básicas de I/O operam em termos de bloco, pois é dificil para o SO localizar um deslocamento dentro de um arquivo.

Arquivos podem ter atributos(mantidos na estrutura de diretório) como:
* Nome
* Identificador
* Tipo
* Localização
* Tamanho
* Proteção
* Hora, data, etc

Para abrir um aquivo(open file) é necessário uma tabela de open-file que mapeai arquivos abertos, um apontador de arquivos, um contador de arquivos abertos, localização no disco e direitos de acesso.
Um arquivo pode ter locks similiares a locks de escrita-leitura.
* Shared lock: diversos processos podem adquirir concorrentemente
* Exclusive lock: apenas um processo por vez pode adquirir esse lock  

* Trancamento obrigatório: o sistema operacional assegura a integridade do trancamento.
* Trancamento aconselhavel:é responsabilidade dos desenvolvedores do software assegurar que os locks sejam apropriadamente adquiridos e liberados. Caso
contrário, eles impedirão que outros processos também o acessem.

A principal tarefa do SO é mapear o conceito de arquivo lógico para dispositivos de armazenamento físicos como as fitas ou discos magnéticos. Já que o tamanho do registro físico do dispositivo pode não ser igual ao tamanho do registro lógico, é necessário ordenar os registros lógicos nos registros físicos. Novamente, esse tarefa pode ser suportada pelo SO, ou pode ser deixada para o programa de aplicação.

Métodos de acesso ás informações de arquivos:
* Acesso sequencial: informações são processadas em ordem, um registro após o outro.
* Acesso direto: os arquivos são compostos por registros lógicos de tamanho fixo que permitem que os programas leiam e gravem registros rapidamente sem uma ordem específica.(função hash)

Cada dispositivo em um sistema de arquivos mantém um índice de volumes ou um diretório de dispositivos que lista a locação dos arquivos no dispositivo. Além disso, é util criar diretórios para permitir a organização dos arquivos. Um diretório de um nível em sistema multiusuário causa problemas de nomeação, já que cada arquivo deve ter um nome exclusivo. Um diretório de dois níveis resolve esse problema criando um diretório separado para os arquivos de cada usuário. O diretório lista os arquivos por nome e inclui a locação do arquivo no disco, seu tamanho, tipo, proprietário, a hora de criação, a hora em que foi usado pela última vez, e assim por diante.

A generalização natural de um diretório de dois níveis é um diretório estruturado em árvore. Um diretório estrutura em árvore permite que um usuário crie subdiretórios para organizar arquivos. As estruturas de diretório em grafo acíclico permitem que os usuários compartilhem subdiretórios e arquivos, mas complicam a busca e a exclusão. Uma estrutura de grafo geral fornece flexibilidade ilimitada ao compartilhamento de arquivos e diretórios, mas às vezes requer que a coleta de lixo recupere espaço não utilizado em disco.

Os discos são segmentados em um ou mais volumes, cada um contendo um sistema de arquivos ou deixado “bruto”. Os sistemas de arquivos podem ser montados nas estruturas de nomeação do sistema para torná-los disponíveis. O esquema de nomeação varia por sistema operacional. Uma vez montados, os arquivos do volume ficam disponíveis para uso. Os sistemas de arquivos podem ser desmontados para desabilitar o acesso ou para manutenção.

O compartilhamento de arquivos depende das semânticas fornecidas pelo sistema. Os arquivos podem ter múltiplos leitores, múltiplos gravadores, ou limites para o compartilhamento. Os sistemas de arquivos distribuídos permitem que hospedeiros clientes montem volumes ou diretórios a partir de servidores, contanto que possam acessar um ao outro por uma rede. Os sistemas de arquivos remotos apresentam desafios quanto à confiabilidade, ao desempenho e à segurança. Os sistemas de informação distribuídos mantêm informações de usuário, hospedeiro e acesso, de modo que clientes e servidores possam compartilhar informações de estado para gerenciar o uso e o acesso.

Como os arquivos são o principal mecanismo de armazenamento de informações na maioria dos sistemas de computação, faz-se necessária a proteção de arquivos. O acesso a arquivos pode ser controlado separadamente para cada tipo de acesso — leitura, gravação, execução, acréscimo, exclusão, listagem de diretório, e assim por diante. A proteção de arquivos pode ser fornecida por listas de controle de acesso, especificando nomes de usuários e os tipos de acesso permitidos a cada usuário. Para condensar a lista de acesso, o SO reconhece três classificações:
* Modos de acesso: leitura, gravação, execução.
* Classes de acesso: Proprietário(usuário que criou o arquivo), Grupo(conjunto de usuários), Universo(todos os usuários no sistema).

# SISTEMAS DE I/O

Os elementos básicos de hardware envolvidos no I/O são buses, controladores de dispositivos e os próprios dispositivos. O trabalho de movimentar dados entre dispositivos e a memória principal é executado pela CPU como I/O programado ou é descarregado para um controlador de DMA. O módulo do kernel que controla um dispositivo é um driver de dispositivo. A interface de chamadas de sistema fornecida para aplicações é projetada para manipular várias categorias básicas de hardware, incluindo dispositivos de blocos, dispositivos de caracteres, arquivos mapeados para a memória, sockets de rede e timers de intervalos programados. As chamadas de sistema usualmente bloqueiam os processos que as emitem, mas chamadas sem bloqueio e assíncronas são usadas pelo próprio kernel e por aplicações que não devem ser suspensas enquanto esperam que uma operação de I/O seja concluída.

O subsistema de I/O do kernel fornece numerosos serviços. Entre eles estão o scheduling de I/O, o armazenamento em buffer, o armazenamento em cache, o spooling, a reserva de dispositivbos e a manipulação de erros. Outro serviço, a tradução de nomes, faz a conexção entre dispositivos de hardware e nomes de arquivo simbólicos usados pelas aplicações. Ele envolve vários níveis de mapeamento que traduzem nomes formados por cadeias de caracteres para drivers de dispositivos e endereços de dispositivos específicos e, então, para endereços físicos de portas de I/O ou controladores de bus. Esse mapeamento pode ocorrer dentro do espaço de nomes do sistema de arquivos ou em um espaço de nomes de dispositivos separado


O STREAMS é uma implementação e uma metodologia que fornece uma base estrutural para a programação de drivers de dispositivos e protocolos de rede usando abordagem modular e incremental. Por meio de fluxos (streams), drivers podem ser empilhados, com dados passando por eles para processamento, de maneira sequencial e bidirecional.

As chamadas de sistema de I/O são caras em termos de consumo da CPU por causa das muitas camadas de software existentes entre um dispositivo físico e uma aplicação. Essas camadas geram overhead proveniente de várias fontes: mudanças de contexto para atravessar o limite de proteção do kernel, manipulação de sinais e de interrupções para servir os dispositivos de I/O, e a carga sobre a CPU e o sistema de memória para copiar dados entre os buffers do kernel e o espaço da aplicação.

















