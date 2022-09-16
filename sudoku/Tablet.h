#ifndef TABLET_H
#define TABLET_H
class grid
{
    int* collumn;
    int* row;
    int** area;
    int** cells;
public:
    int* get_row(int r);
    int* get_collumn(int c);
    int** get_area(int a);

    void set_collumn(int* c, int n);
    void set_row(int* r, int n);


    grid();
    ~grid();

    bool check_area(int** a);
    bool check_row(int* r);
    bool check_collumn(int* c);

    void shuffle();
    void shuffle_rows();
    void shuffle_collumns();
    void shuffle_areas();

    void collumn_shift(int c, int n);
    void row_shift(int r, int n);

    void TransposeTable();
    void Print();

};


#endif // TABLET_H
