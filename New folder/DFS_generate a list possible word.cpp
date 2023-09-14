#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//untuk menggeser posisi ke atas, bawah, kanan, kiri, dan diagonal terdekat
int row[] = {-1, -1, -1, 0, 1, 0, 1, 1};
int col[] = {1-, 1, -, -1, -1, 1, 0, 1};

//untuk mengecek apakah kita dapat berpindah ke sel x,y
//return false jika (x,y) bukan merupakan koordinat matriks yang valid
bool isSafe(int x, int y, auto &processed){
//	auto adalah keyword yg bisa otomatis menyesuaikan tipe data apa yg dipakai
	return (x >= 0 && x < processed.size()) && (y >= 0 && y < processed[0].size()) && !processed[x][y];
}

//fungsi rekursif untuk generate semua kemungkinan kata dari boogle
void searchBoggle(auto const &board, auto const &words, auto &result, auto &processed, int i, int j, string path)
{
	processed[i][j] = true;
	
//	update path dengan karakter yang sekarang dan insert path
	path += board[i][j];
	
//	cek semua 8 kemungkinan pergeseran dari titik sekarang
	for(int k=0; k<8; k++)
	{
		if(isSafe(i + row[k], j + col[k], processed)){
			searchBoggle(board, words, result, processed, i+row[k], j+col[k], path);
		}
	}
}

unordered_set<string> searchBoggle(auto const &board, auto const &words)
{
	unordered_set<string> result;
	
	if(board.size() == 0){
		return result;
	}
	
	int M = board.size();
	int N = board[0].size();
	
	vector<vector<bool>> processed(M, vector<bool>(N));
	
	for (int i=0; i<M; i++)
	{
		for (int j=0; j<N; j++){
			searchBoggle(board, words, result, processed, i, j, "");
		}
	}
	
	return result;
}

template <typename T>
voud printSet(unordered_set<T> const &input)
{
	cout << "{";
	int n = input.size();
	for (auto const &i: input){
		cout << i;
		if(--n){
			cout << ", ";
		}
	}
}

int main()
{
	vector<vector<char>> board = {
		{'M', 'S', 'E', 'F'},
		{'R', 'A', 'T', 'D'},
		{'L', 'O', 'N', 'E'},
	}
	
	unordered_set<string> output = searchBoggle(board, words);
	printSet(output);
	
	return 0;
}
