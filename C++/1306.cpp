#include <iostream>
#include <vector>

std::vector<int> Tree;

void updateTree(int Node, int Begin, int End, int Index, int Intensity)
{
    if (Index < Begin || Index > End)
        return;
    if (Begin == End)
    {
        Tree[Node] = Intensity;
        return;
    }
    int Mid = (Begin + End) / 2;
    updateTree(Node * 2, Begin, Mid, Index, Intensity);
    updateTree(Node * 2 + 1, Mid + 1, End, Index, Intensity);
    Tree[Node] = std::max(Tree[Node * 2], Tree[Node * 2 + 1]);
}

int findMax(int Node, int Begin, int End, int Left, int Right)
{
    if (Left > End || Right < Begin)
        return 0;
    if (Left <= Begin && Right >= End)
        return Tree[Node];
    int Mid = (Begin + End) / 2;
    return std::max(findMax(Node * 2, Begin, Mid, Left, Right),
        findMax(Node * 2 + 1, Mid + 1, End, Left, Right));
}


int main()
{
    int N, M, Intensity;
    std::cin >> N >> M;
    Tree.resize(N * 4 + 1);

    for (int i = 1  ; i <= N; i++)
    {
        std::cin >> Intensity;
        updateTree(1, 1, N, i, Intensity);
    }

    for (int i = M; i <= N - M + 1; i++)
        std::cout << findMax(1, 1, N, i-(M-1), i + (M - 1)) << ' ';
}