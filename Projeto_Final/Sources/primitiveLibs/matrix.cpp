#include "matrix.h"

//#####Início Verificação de tipos de Matrizes#####//
template <class UsedType>
bool Matrix<UsedType>::sqr(Matrix<UsedType> Mat1)//Verifica se a matriz é quadrada.
{
    bool vef;

    if (Mat1.rows == Mat1.cols)
        vef = true;
    else
        vef = false;

    return vef;
}

template <class UsedType>
bool Matrix<UsedType>::ind(Matrix<UsedType> Mat1)//Verifica se a matriz é identidade.
{
    bool vef;
    int x = 0, a = 0, b = 0;

    for (int i = 0; i < Mat1.rows; i ++)//Neste for o valor de x
        for(int j = 0; j < Mat1.rows; j++)//será igual a quantidade 1
            if ((i == j) && (Mat1.Mat[i][j]) == 1)//que se encontram na diagonal principal da matriz.
                x++;
    for(int i = 0; i < Mat1.rows; i++ )//Este for navega pelos elementos
        for(int j = i+1; j < Mat1.cols; j++)//acima da diagonal principal
        {                                   //verificando se algum deles for diferente de 0
            if (Mat1.Mat[i][j] != 0)        //se algum número for diferente de 0, o for é quebrado.
            {                               //Caso não a é incrementado.
                i = Mat1.rows + 1;
                a = -1;
                break;
            }
            else
                a++;
        }


    for(int i = 0; i < Mat1.rows; i++ )//Este for navega pelos elementos
        for(int j = i+1; j < Mat1.cols; j++)//abaixo da diagonal principal
        {                                   //verificando se algum deles for diferente de 0
            if (Mat1.Mat[j][i] != 0)        //se algum número for diferente de 0, o for é quebrado.
            {                                //Caso não b é incrementado.
                i = Mat1.rows +1;
                b = -1;
                break;
            }
            else
                b++;
        }

    if (x == (Mat1.rows) && (a != -1) && (b != -1))//Verifica se x possui o mesmo valor
        vef = true;                                //das linhas da matriz, e se foi encontrado
    else                                           //elementos diferente de 0 acima ou abaixo da diagonal principal.
        vef = false;

    return vef;
}
//#####Fim Verificação de tipos de Matrizes#####//

//#####Início Construtores e Destrutores da Classe#####//

template <class UsedType>
Matrix<UsedType>::Matrix() //Inicializa linhas e colunas com zero
{
    this->rows = 0;
    this->cols = 0;
}

template <class UsedType>
Matrix<UsedType>::Matrix(int row, int col)//Inicializa a Matriz com as linhas e colunas determinadas.
{
    this->init(row, col);
}

template <class UsedType>
Matrix<UsedType>::Matrix(const Matrix<UsedType> & otherMatrix)//Cria uma cópia da Matriz
{

    this->init(otherMatrix.rows, otherMatrix.cols);
    for (int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
            this->Mat[i][j] = otherMatrix.Mat[i][j];
}

template <class UsedType>
Matrix<UsedType>::~Matrix()//Destrutor da Classe Matriz
{
    if ((this->rows != 0) && (this->cols != 0))
    {
        for (int i = 0; i < this->rows; i++)
        {
            free(this->Mat[i]);
            this->Mat[i] = NULL;
        }
        free(this->Mat);
        this->rows = 0;
        this->cols = 0;
        this->Mat = NULL;
    }
}
//#####Fim Construtores e Destrutores da Classe#####//

//#####Início Métodos de Inicialização de Matrizes#####//

template <class UsedType>
void Matrix<UsedType>::init(int row, int col)//Aloca o espaço de memória para a Matriz e inicializa com 0
{
    this->Mat = (UsedType**)calloc(col,(row)*sizeof(UsedType*)); //Cria as linhas
    for (int i = 0; i < row; i++)
        this->Mat[i] = (UsedType*)calloc(col,(col)*sizeof(UsedType)); //Cria as colunas
    this->rows = row;
    this->cols = col;
}

template <class UsedType>
void Matrix<UsedType>::init(string value)//Inicializa a Matriz com uma cadeia de strings como entrada
{
    int posComma, posSemiComma, col = 1, row = 1;
    string temp;

    while (!value.empty())
    {
        posSemiComma = value.find(";");
        if (posSemiComma != -1)
            temp = value.substr(0,posSemiComma);
        else
        {
            temp = value;
            posSemiComma = value.length();
        }
        while (!temp.empty())
        {
            posComma = temp.find(",");
            if( posComma == -1)
                posComma = temp.length();

            string temp2 = temp.substr(0, posComma);
            UsedType num = (UsedType)atof(temp2.c_str());
            this->add(row, col, num);
            temp.erase(0, posComma+1);
            col++;
        }
        value.erase(0,posSemiComma+1);
        col = 1;
        row++;
    }
}

template <class UsedType>
void Matrix<UsedType>::add(int row, int col, UsedType number)//Adiciona valores a matriz,
{                                               //se tiver valores maiores que as dimensões da matriz, coloca o valor na posição indicada completando o resto com 0
     Matrix<UsedType> Temp;

    if (this->rows < row || this->cols < col)
    {
        if(this->rows == 0 || this->cols == 0)
            this->init(1,1);

        if (this->rows < row && row > 0)
           Temp.init(row, this->cols);
        else
           Temp.init(this->rows, col);

        if((this->rows != 0) && (this->cols != 0))
        {
            for(int i = 0; i < this->rows; i++)
                for (int j = 0; j < this->cols; j++)
                    Temp.Mat[i][j] = this->Mat[i][j];
        }
        Temp.Mat[row-1][col-1] = number;
        this->init(Temp.rows, Temp.cols);

        for(int i = 0; i < this->rows; i++)
            for (int j = 0; j < this->cols; j++)
                this->Mat[i][j] = Temp.Mat[i][j];
    }
    else
        this->Mat[row-1][col-1] = number;


}

template <class UsedType>
void Matrix<UsedType>::eye(int num)//Gera uma Matriz Identidade, entrando como parâmetro a dimensão quadrada da Matriz
{
    this->init(num,num);
    for(int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
            if (i == j)
                this->Mat[i][j] = 1;

}

template <class UsedType>
void Matrix<UsedType>::ones(int row, int col)//Cria uma matriz preenchida com 1s.
{
    this->init(row, col);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            this->Mat[i][j] = 1;
}

template <class UsedType>
void Matrix<UsedType>::zeros(int row, int col)//Gera uma Matriz de Zeros, tendo como entrada as dimensões indicadas.
{
    this->init(row, col);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            this->Mat[i][j] = 0;
}

template <class UsedType>
void Matrix<UsedType>::randU(int row, int col)
{
    srand((time(NULL)));
    UsedType t;
    this->init(row, col);
    for(int i = 0; i < this->rows; i++)
        for(int j = 0; j < this->cols; j++)
        {
            t = (UsedType)rand()/RAND_MAX;
            this->Mat[i][j] = t;
        }
}

template <class UsedType>
int Matrix<UsedType>::length()
{
    int tam;

    if(this->rows > this->cols)
        tam = this->rows;
    else
        tam = this->cols;

    return tam;
}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::Avarage()
{
    Matrix<UsedType> ret;
    ret.zeros(1, this->cols);
    for(int i = 0; i < this->rows; i++)
        for(int j = 0; j < this->cols; j++)
            ret.Mat[0][j] = ret.Mat[0][j] + (this->Mat[i][j])/this->cols;

    return ret;
}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::Variance()
{
    Matrix<UsedType> Media, ret;

    Media = this->Avarage();
    ret.zeros(1, this->cols);
    for(int i = 0; i < this->rows; i++)
        for(int j = 0; j < this->cols; j++)
            ret.Mat[0][j] = ret.Mat[0][j] + pow((this->Mat[i][j]-Media.Mat[0][j]),2)/this->cols;

    return ret;


}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::Std()
{
    Matrix<UsedType> ret, Variancia;

    Variancia = this->Variance();
    ret.zeros(1, this->cols);

    for(int i = 0; i < this->rows; i++)
        ret.Mat[0][i] = sqrt(Variancia.Mat[0][i]);

    return ret;
}

template <class UsedType>
void Matrix<UsedType>::print()//Imprime a Matriz na Tela
{
    cout<<"\n";
    for (int i = 0; i< this->rows; i++)
    {
        for (int j = 0; j< this->cols; j++)
        {
            printf("%6.3f", (float)this->Mat[i][j]);
            cout<<" ";
        }
        cout<<endl;
    }
}

//#####Fim Métodos de Inicialização de Matrizes#####//

//#####Início Sobrecarga de Operadores#####//

//-----Início Operadores de Soma-----//
template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::operator +(Matrix<UsedType> Mat1)//Operador de soma Matriz Matriz
{
    Matrix<UsedType> Ret(this->rows, this->cols);

    for(int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
            Ret.Mat[i][j] = this->Mat[i][j] + Mat1.Mat[i][j];

    return Ret;
}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::operator +(UsedType a)//Operador de soma Escalar Matriz
{
    Matrix<UsedType> Ret(this->rows, this->cols);

    for(int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
            Ret.Mat[i][j] = this->Mat[i][j] + a;

    return Ret;
}

template <class UsedType>
Matrix<UsedType> operator+(UsedType a, Matrix<UsedType> Mat1)//Operador de soma Matriz Escalar
{
    return Mat1+a;
}
//-----Fim Operadores de Soma-----//

//-----Início Operadores de Subtração-----//
template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::operator -(Matrix<UsedType> Mat1)//Operador de subtração Matriz Matriz
{
    Matrix<UsedType> Ret(this->rows, this->cols);

    for(int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
            Ret.Mat[i][j] = this->Mat[i][j] - Mat1.Mat[i][j];

    return Ret;
}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::operator -(UsedType a)//Operador de subtração Escalar Matriz
{
    Matrix<UsedType> Ret(this->rows, this->cols);

    for(int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
            Ret.Mat[i][j] = this->Mat[i][j] - a;

    return Ret;
}

template <class UsedType>
Matrix<UsedType> operator-(UsedType a, Matrix<UsedType> Mat1)//Operador de subtração Matriz Escalar
{
    return Mat1-a;
}
//-----Fim Operadores de Subtração-----//

//-----Início Operadores de Igualdade-----//

template <class UsedType>
void Matrix<UsedType>::operator= (Matrix<UsedType> Mat1)//Operador de Igualdade entre Matrizes
{
    this->init(Mat1.rows, Mat1.cols);

    for(int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
            this->Mat[i][j] = Mat1.Mat[i][j];
}

template <class UsedType>
void Matrix<UsedType>::operator=(string value)//Operador para a entrada de uma String
{
    this->init(value);
}

//-----Fim Operadores de Igualdade-----//

//-----Início Operadores de Multplicação-----//
template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::operator *(Matrix<UsedType> Mat1)//Operador de Multiplicação Matriz Matriz
{

    UsedType temp = 0;
    Matrix<UsedType> Ret(this->rows, Mat1.cols);

    try
    {
        if(this->cols == Mat1.rows)
        {
            for(int i = 0; i < this->rows; i++)
            {
                for (int col = 0; col < Mat1.cols; col++)
                {
                    temp = 0;
                    for (int j = 0; j < this->cols; j++)
                        temp += this->Mat[i][j]*Mat1.Mat[j][col];
                    Ret.Mat[i][col] = temp;
                }

            }

            return Ret;
       }

        else
        {
            throw "As dimensoes das matrizes nao batem, a multiplicacao nao e possivel";
            Ret.zeros(this->rows, Mat1.cols);
        }
    }
    catch(const char* msg)
    {
        cerr<<endl<<msg<<endl;
    }
    return Ret;
}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::operator *(UsedType a)//Operador de multiplicação Escalar Matriz
{
    Matrix<UsedType> Ret(this->rows, this->cols);

    for(int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
            Ret.Mat[i][j] = a*this->Mat[i][j];

    return Ret;
}

template <class FriendType>
Matrix<FriendType> operator*(FriendType a, Matrix<FriendType> Mat1)//Operador de multiplicação Matriz Escalar
{
    return Mat1*a;
}
//-----Fim Operadores de Multiplicação-----//

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::operator /(Matrix<UsedType> Mat1)//Operador de Multiplicação Matriz Matriz
{
    if(Mat1.rows == 1 && Mat1.cols == 1)
        return (*this)/(Mat1(1,1));
    else if(this->rows == 1 && this->cols == 1)
        return ((*this)(1,1))*Mat1.inv();
    else
        return (*this)*Mat1.inv();
}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::operator/ (UsedType a)//Operador de multiplicação Escalar Matriz
{
    Matrix<UsedType> Ret(this->rows, this->cols);

    for(int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
            Ret.Mat[i][j] = this->Mat[i][j]/a;

    return Ret;
}

template <class FriendType>
Matrix<FriendType> operator/ (FriendType a, Matrix<FriendType> Mat1)//Operador de multiplicação Matriz Escalar
{
    return a*Mat1.inv();
}


//-----Início Operadores de Concatenação Matrizes-----//
template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::operator|(Matrix<UsedType> Mat1)//Concatenção de Matrizes a Esquerda
{
    Matrix<UsedType> temp(this->rows,this->cols+Mat1.cols);

    for(int i = 0; i < temp.rows; i++)
        for (int j = 0; j < temp.cols; j++)
            if(j<this->cols)
                temp.add(i+1,j+1,this->Mat[i][j]);
            else
                temp.add(i+1,j+1,Mat1.Mat[i][j-this->cols]);

    return temp;

}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::operator||(Matrix<UsedType> Mat1)//Concatenação de Matrizes Abaixo
{
    Matrix<UsedType> temp(this->rows+Mat1.rows,this->cols);

    if(this->rows == 0 and this->cols == 0)
        temp = Mat1;
    else
    {
        for(int j = 0; j < temp.cols; j++)
            for (int i = 0; i < temp.rows; i++)
                if(i<this->rows)
                    temp.add(i+1,j+1,this->Mat[i][j]);
                else
                temp.add(i+1,j+1,Mat1.Mat[i-this->rows][j]);
    }

    return temp;

}
//-----Fim Operadores de Concatenação Matrizes-----//

//----Início Operador de Matriz Transposta-----//
template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::operator~()//Faz a transporta da Matriz
{
    Matrix<UsedType> Ret (this->cols, this->rows);
    for(int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
                Ret.Mat[j][i] = this->Mat[i][j];

    return Ret;
}
//----Fim Operador de Matriz Transposta-----//

//-----Início Operador de Potência de Matrizes-----//
template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::operator^(UsedType exp)
{
    Matrix<UsedType> Ret, temp = *this;

    Ret.eye(this->rows);

    if(exp < 0)
    {
        temp = this->inv();
        exp = exp*(-1);
    }


    Ret.eye(this->rows);

    for(int i = 0; i < exp; i++)
    {
            Ret = Ret*temp;
    }

    return Ret;
}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::operator >(UsedType num)//Eleva os elementos da Matriz a um determinado expoente
{
    Matrix<UsedType> Ret = *this;

    for(int i = 0; i < Ret.rows; i++)
        for(int j = 0; j < Ret.cols; j++)
            Ret.Mat[i][j] = pow(this->Mat[i][j],num);

    return Ret;
}
//-----Fim Operador de Potência de Matrizes-----//

//#####Fim Sobrecarga de Operadores#####//

//#####Início Álgebra Linear#####//
template <class UsedType>
UsedType Matrix<UsedType>::trace()//Cálcula o Traço da Matriz
{
   UsedType traco = 0;

   try
   {
        if(!this->sqr(*this))
            throw "A matrix nao e quadrada";
        else
            for(int i = 0; i < this->rows; i++ )
                for(int j = 0; j < this->cols; j++)
                    if( i == j)
                        traco = traco + this->Mat[i][j];
   }
   catch (const char* msg)
   {
        cerr<<msg<<endl;
   }

    return traco;
}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::inv()//Encontra a Matriz Inversa.
{
    Matrix<UsedType> Ret =*this, Id;


    try
    {
        if (!this->sqr(*this))
            throw "A matriz nao e quadrada";
        else
        {
            Id.eye(this->rows);

            for(int i = 0; i < this->rows; i++ )
                for(int j = i+1; j<this->rows; j++)
                {
                    UsedType m = Ret.Mat[j][i]/Ret.Mat[i][i];
                    for(int k = 0; k <this->cols; k++)
                    {
                        Ret.Mat[j][k] = Ret.Mat[j][k]-m*Ret.Mat[i][k];
                        Id.Mat[j][k] = Id.Mat[j][k]-m*Id.Mat[i][k];
                    }
                }


            for(int i = this->rows-1; i >=0 ; i-- )
                for(int j = i-1; j>=0; j--)
                {
                    UsedType m = Ret.Mat[j][i]/Ret.Mat[i][i];
                    for(int k = 0; k <this->cols; k++)
                    {
                        Ret.Mat[j][k] = Ret.Mat[j][k]-m*Ret.Mat[i][k];
                        Id.Mat[j][k] = Id.Mat[j][k]-m*Id.Mat[i][k];
                    }
                }

            for(int i=0; i< this->rows; i++)
            {
                UsedType m = 1/Ret.Mat[i][i];
                for(int j=0; j<this->rows; j++)
                {
                     Ret.Mat[i][j] = m*Ret.Mat[i][j];
                     Id.Mat[i][j] = m*Id.Mat[i][j];
                }

            }
        }

    }

    catch (const char* msg)
    {
        cerr<<msg<<endl;
    }

    return Id;
}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::pol()//Encontra os Índices do Polinômio Característico
{
    Matrix<UsedType> A = *this, B, I, C, ind(1, this->cols + 1);
    int sinal;

    try
    {
         if(!this->sqr(*this))
             throw "A matrix nao e quadrada";
         else
             I.eye(this->rows);
             C = A;
             sinal = pow(-1, this->rows);
             ind.Mat[0][0] = 1;
             for(int i = 1; i <= this->rows; i++ )
             {
                    ind.Mat[0][i] = (C.trace()/i);
                    B = C - ind.Mat[0][i]*I;
                    C = A*B;
                    ind.Mat[0][i] = -ind.Mat[0][i];

             }
             for (int i = 0; i < (ind.cols); i++)
                 ind.Mat[0][i] = ind.Mat[0][i]*sinal;

    }
    catch (const char* msg)
    {
         cerr<<msg<<endl;
    }

    return ind;
}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::eigenvalues()//Encontra os Auto Valores da Matriz.
{
    Matrix<UsedType> autovlr(1, this->rows);

    try
    {
       if (!this->sqr(*this))
           throw "A matrix não é quadrada";
       else
           if (!this->ind(*this))
       {
                   Matrix<UsedType> Q, temp, R, A = *this;
                   UsedType max = 1000;

                   Q.eye(this->rows);
                   R.eye(this->rows);
                   while (max > 0.00001)
                   {
                       for(int i = 0; i < this->rows; i++ )
                           for(int j = i+1; j<this->rows; j++)
                               {
                                        temp.eye(this->rows);
                                        if (A.Mat[i][j] != 0)
                                        {
                                            temp.Mat[i][i] = (A.Mat[i][i])/sqrt(pow(A.Mat[i][i],2) + pow(A.Mat[i][j],2));
                                            temp.Mat[j][j] = temp.Mat[i][i];
                                            temp.Mat[i][j] = (A.Mat[i][j])/sqrt(pow(A.Mat[i][i],2) + pow(A.Mat[i][j],2));
                                            temp.Mat[j][i] = - temp.Mat[i][j];
                                        }
                                       R = temp*A;
                                       A = R*(~temp);
                           }
                       for(int i = 0; i < this->rows; i++ )
                           for(int j = i+1; j< this->rows; j++)
                           {
                               if ((A.Mat[i][j] > 0) && (A.Mat[i][j]) < max)
                                   max = A.Mat[i][j];
                               else if((A.Mat[i][j] < 0) && (-1*A.Mat[i][j]) < max)
                                   max = -1*(A.Mat[i][j]);
                           }
                    }
                   for(int i = 0; i < this->rows; i++ )
                       for(int j = 0; j< this->rows; j++)
                           if (i == j)
                                autovlr.Mat[0][i] = A.Mat[i][j];
       }
            else
               for(int i = 0; i < this->rows; i++ )
                   autovlr.Mat[0][i] = 1;

      }

    catch (const char* msg)
    {
        cerr<<msg<<endl;
    }

    return autovlr;
}

template <class UsedType>
UsedType Matrix<UsedType>::det()//Encontra o determinante da Matriz.
{
    UsedType x = 1;
    Matrix<UsedType> A;

    try
    {
        if (!this->sqr(*this))
            throw "A matrix não é quadrada";
        else if(!this->ind(*this))
             {
                A = this->eigenvalues();

                for (int i = 0; i < A.cols; i++)
                    x *= A.Mat[0][i];
             }
             else
                x = 1;
    }
    catch (const char* msg)
    {
        cerr<<msg<<endl;
    }

    return x;
}

template <class FriendType>
Matrix<FriendType> diff(Matrix<FriendType> M, FriendType h)//Encontra a derivada de uma Matriz
{
    Matrix<FriendType> Ret;
    for(int i = 0; i < M.rows-1; i++)
        for(int j = 0; j < M.cols; j++)
            Ret.add(i+1,j+1,(M.Mat[i+1][j] - M.Mat[i][j])/h);

    return Ret;
}

//#####Fim Álgebra Linear#####//

//#####Início Funções de Retorno de Informações da Matriz#####//
template <class UsedType>
int Matrix<UsedType>::getRows()//Retorna o numéro de linhas de uma Matriz.
{
    return this->rows;
}

template <class UsedType>
int Matrix<UsedType>::getCols()//Retorna o numéro de colunas de uma Matriz.
{
    return this->cols;
}

template <class UsedType>
void Matrix<UsedType>::setLine(int num, Matrix<UsedType> Line)
{
    try
    {
        if(!(this->getCols() == Line.getCols()))
            throw "Numero de colunas incompativel";
        else
        {
            for(int i = 0; i < Line.getCols(); i++)
                this->Mat[num-1][i] = Line.Mat[num-1][i];
        }
    }
    catch(const char* msg)
    {
        cerr<<msg<<endl;
    }
}

template <class UsedType>
void Matrix<UsedType>::setColumn(int num, Matrix<UsedType> Column)
{
    try
    {
        if(!(this->getRows() == Column.getRows()))
            throw "Numero de linhas incompativel";
        else
        {
            for(int i = 0; i < Column.getRows(); i++)
                this->Mat[i][num-1] = Column.Mat[i][num-1];
        }
    }
    catch(const char* msg)
    {
        cerr<<msg<<endl;
    }
}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::getLine(int num)
{
    Matrix<UsedType> ret(1,this->cols);

    for (int i = 0; i < this->cols; i++)
        ret.Mat[0][i] = this->Mat[num-1][i];

    return ret;
}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::getColumn(int num)
{
    Matrix<UsedType> ret(this->rows, 1);

    for (int i = 0; i < this->rows; i++)
        ret.Mat[i][0] = this->Mat[i][num-1];

    return ret;
}

//UsedType Matrix::getMat(int row, int col)//Retorna o valor do elemento no índice ij.
//{
//    return this->Mat[row-1][col-1];
//}
//#####Fim Funções de Retorno de Informações da Matriz#####//
//-----Funções Auxiliares para biblioteca de matrizes------//

template <class UsedType>
UsedType Matrix<UsedType>::max()
{
    UsedType  maximum = this->Mat[0][0];
     if(this->rows != 0 && this->cols != 0)
         for(int i = 0; i < this->rows; i++)
            for(int j = 0; j < this->cols; j++)
                if(maximum < this->Mat[i][j])
                    maximum = this->Mat[i][j];

     return maximum;
}
template <class UsedType>
UsedType Matrix<UsedType>::min()
{
    UsedType  minimun;
    minimun = this->Mat[0][0];
    if(this->rows != 0 && this->cols != 0)
        for(int i = 0; i < this->rows; i++)
            for(int j = 0; j < this->cols; j++)
                if(minimun > this->Mat[i][j])
                    minimun = this->Mat[i][j];

    return minimun;
}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::normalize(UsedType yUp, UsedType yDown)
{
  Matrix<UsedType>  ret;
  ret.init(this->getRows(),this->getCols());
  UsedType xDown = this->min(), xUp = this->max();

  for(int i = 0; i < this->rows; i++)
    for(int j = 0; j < this->cols; j++)
        ret(i+1,j+1,((this->Mat[i][j] - xDown)/(xUp - xDown))*(yUp - yDown) + yDown);

  return ret;
}

template <class UsedType>
UsedType Matrix<UsedType>::operator()(int row, int col)
{
    return this->Mat[row-1][col-1];
}

template <class UsedType>
void Matrix<UsedType>::operator ()(int row, int col, UsedType value)
{
    this->add(row, col, value);
}

template <class UsedType>
void Matrix<UsedType>::lineVector(int left, int rigth)
{
    int j = 1;
    if (left > rigth)
        for(int i = left; i >= rigth; i--)
        {
            this->add(1,j, i);
            j++;
        }
    else
        for(int i = left; i <= rigth; i++)
        {
            this->add(1,j, i);
            j++;
        }
}

template <class UsedType>
Matrix<UsedType> abs(Matrix<UsedType> M)
{
    Matrix<UsedType> ret = M;
    for(  int i = 0; i < M.rows; i++)
        for(  int j = 0; j < M.cols; j++)
            if (ret.Mat[i][j] < 0)
                ret.Mat[i][j] = -ret.Mat[i][j];

    return ret;
}

//-----------------------------------------------------//

template <class UsedType>
Matrix<UsedType> cos(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, cos(M1(i+1,j+1)));

    return ret;

}

template <class UsedType>
Matrix<UsedType> sin(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, sin(M1(i+1,j+1)));

    return ret;
}

template <class UsedType>
Matrix<UsedType> tan(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, tan(M1(i+1,j+1)));

    return ret;

}

template <class UsedType>
Matrix<UsedType> acos(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, acos(M1(i+1,j+1)));

    return ret;


}

template <class UsedType>
Matrix<UsedType> asin(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, asin(M1(i+1,j+1)));

    return ret;


}

template <class UsedType>
Matrix<UsedType> atan(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, atan(M1(i+1,j+1)));

    return ret;

}

template <class UsedType>
Matrix<UsedType> cosh(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, cosh(M1(i+1,j+1)));

    return ret;

}

template <class UsedType>
Matrix<UsedType> sinh(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, sinh(M1(i+1,j+1)));

    return ret;


}

template <class UsedType>
Matrix<UsedType> tanh(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, tanh(M1(i+1,j+1)));

    return ret;


}

template <class UsedType>
Matrix<UsedType> acosh(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, acosh(M1(i+1,j+1)));

    return ret;


}

template <class UsedType>
Matrix<UsedType> asinh(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, asinh(M1(i+1,j+1)));

    return ret;


}

template <class UsedType>
Matrix<UsedType> atanh(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, atanh(M1(i+1,j+1)));

    return ret;

}

template <class UsedType>
Matrix<UsedType> exp(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, exp(M1(i+1,j+1)));

    return ret;


}

template <class UsedType>
Matrix<UsedType> log(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, log(M1(i+1,j+1)));

    return ret;


}

template <class UsedType>
Matrix<UsedType> log10(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, log10(M1(i+1,j+1)));

    return ret;


}

template <class UsedType>
Matrix<UsedType> ceil(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, ceil(M1(i+1,j+1)));

    return ret;


}

template <class UsedType>
Matrix<UsedType> floor(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, floor(M1(i+1,j+1)));

    return ret;
}

template <class UsedType>
Matrix<UsedType> round(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, round(M1(i+1,j+1)));

    return ret;
}

template <class UsedType>
UsedType norm(Matrix<UsedType> M1)
{
    UsedType sum = 0;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            sum += pow(M1(i+1,j+1), 2);

    return sqrt(sum);
}

//double operator ^(double num1, double num2)
//{
//    return pow(num1,num2);
//}
//template Matrix<double>::Matrix<double>();
//--------------------------------------------------------------------------------//
template class Matrix<char>;
template class Matrix<bool>;
//-----------------------------Int Template---------------------------------------//
template class Matrix<int>;
//template Matrix<int> operator+<int> (int, Matrix<int>);
//template Matrix<int> operator-<int> (int, Matrix<int>);
template Matrix<int> operator*<int> (int, Matrix<int>);
template Matrix<int> operator/<int> (int, Matrix<int>);
template Matrix<int> diff<int> (Matrix<int>, int);
//template int max<int> (Matrix<int>);
//template int min<int> (Matrix<int>);
//template int norm<int> (Matrix<int>);
//template Matrix<int> abs<int> (Matrix<int>);
//template Matrix<int> cos<int> (Matrix<int>);
//template Matrix<int> sin<int> (Matrix<int>);
//template Matrix<int> tan<int> (Matrix<int>);
//template Matrix<int> acos<int> (Matrix<int>);
//template Matrix<int> asin<int> (Matrix<int>);
//template Matrix<int> atan<int> (Matrix<int>);
//template Matrix<int> cosh<int> (Matrix<int>);
//template Matrix<int> sinh<int> (Matrix<int>);
//template Matrix<int> tanh<int> (Matrix<int>);
//template Matrix<int> acosh<int> (Matrix<int>);
//template Matrix<int> asinh<int> (Matrix<int>);
//template Matrix<int> atanh<int> (Matrix<int>);
//template Matrix<int> exp<int> (Matrix<int>);
//template Matrix<int> log<int> (Matrix<int>);
//template Matrix<int> log10<int> (Matrix<int>);
template Matrix<int> ceil<int> (Matrix<int>);
template Matrix<int> round<int> (Matrix<int>);
template Matrix<int> floor<int> (Matrix<int>);
//-------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------//
//-----------------------------Double Template---------------------------------------//
template class Matrix<double>;
//template Matrix<double> operator+<double> (double, Matrix<double>);
//template Matrix<double> operator-<double> (double, Matrix<double>);
//template Matrix<double> operator=<double> (double, Matrix<double>);
template Matrix<double> operator*<double> (double, Matrix<double>);
template Matrix<double> operator/<double> (double, Matrix<double>);
template Matrix<double> diff<double> (Matrix<double>, double);
//template double max<double> (Matrix<double>);
//template double min<double> (Matrix<double>);
template double norm<double> (Matrix<double>);
template Matrix<double> abs<double> (Matrix<double>);
template Matrix<double> cos<double> (Matrix<double>);
template Matrix<double> sin<double> (Matrix<double>);
template Matrix<double> tan<double> (Matrix<double>);
template Matrix<double> acos<double> (Matrix<double>);
template Matrix<double> asin<double> (Matrix<double>);
template Matrix<double> atan<double> (Matrix<double>);
template Matrix<double> cosh<double> (Matrix<double>);
template Matrix<double> sinh<double> (Matrix<double>);
template Matrix<double> tanh<double> (Matrix<double>);
template Matrix<double> acosh<double> (Matrix<double>);
template Matrix<double> asinh<double> (Matrix<double>);
template Matrix<double> atanh<double> (Matrix<double>);
template Matrix<double> exp<double> (Matrix<double>);
template Matrix<double> log<double> (Matrix<double>);
template Matrix<double> log10<double> (Matrix<double>);
template Matrix<double> ceil<double> (Matrix<double>);
template Matrix<double> round<double> (Matrix<double>);
template Matrix<double> floor<double> (Matrix<double>);
//-------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------//
//-----------------------------Float Template---------------------------------------//
template class Matrix<float>;
//template Matrix<float> operator+<float> (float, Matrix<float>);
//template Matrix<float> operator-<float> (float, Matrix<float>);
template Matrix<float> operator*<float> (float, Matrix<float>);
template Matrix<float> operator/<float> (float, Matrix<float>);
template Matrix<float> diff<float> (Matrix<float>, float);
//template float max<float> (Matrix<float>);
//template float min<float> (Matrix<float>);
template float norm<float> (Matrix<float>);
template Matrix<float> abs<float> (Matrix<float>);
template Matrix<float> cos<float> (Matrix<float>);
template Matrix<float> sin<float> (Matrix<float>);
template Matrix<float> tan<float> (Matrix<float>);
template Matrix<float> acos<float> (Matrix<float>);
template Matrix<float> asin<float> (Matrix<float>);
template Matrix<float> atan<float> (Matrix<float>);
template Matrix<float> cosh<float> (Matrix<float>);
template Matrix<float> sinh<float> (Matrix<float>);
template Matrix<float> tanh<float> (Matrix<float>);
template Matrix<float> acosh<float> (Matrix<float>);
template Matrix<float> asinh<float> (Matrix<float>);
template Matrix<float> atanh<float> (Matrix<float>);
template Matrix<float> exp<float> (Matrix<float>);
template Matrix<float> log<float> (Matrix<float>);
template Matrix<float> log10<float> (Matrix<float>);
template Matrix<float> ceil<float> (Matrix<float>);
template Matrix<float> round<float> (Matrix<float>);
template Matrix<float> floor<float> (Matrix<float>);
//-------------------------------------------------------------------------------//




