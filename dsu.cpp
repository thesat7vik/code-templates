const int N = 2e5 + 1;
int parent[N];
int sized[N];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    sized[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sized[a] < sized[b])
            swap(a, b);
        parent[b] = a;
        sized[a] += sized[b];
    }
}
