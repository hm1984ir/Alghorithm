#include <vector>
#include <utility>
#include <array>
#include <iostream>

using namespace std;

struct Subset {
 public:
  int bit_mask;
  int sum;
};

vector<pair<Subset, Subset>> fetch_all_set_combination(int subset,
                                                       int pieces[15], int n) {
  vector<pair<Subset, Subset>> all_combination;
  vector<int> indexes;
  int subset_size{};

  for (int i = 0; i < n; i++) {
    if (subset & 1 << i) {
      indexes.push_back(i);
      subset_size++;
    }
  }

  for (int i = 1; i < 1 << (subset_size - 1); i++) {
    Subset s1 = {};
    Subset s2 = {};

    for (int j = 0; j < subset_size; j++) {
      if (i & 1 << j) {
        s1.bit_mask |= 1 << indexes[j];
        s1.sum += pieces[indexes[j]];
      } else {
        s2.bit_mask |= 1 << indexes[j];
        s2.sum += pieces[indexes[j]];
      }
    }

    all_combination.push_back(pair<Subset,Subset>(s1, s2));
  }

  return all_combination;
}

bool match_in(vector<vector<int>> m, int x, int subset, int n, int pieces[15]) {
  if (m[x][subset] != -1) return m[x][subset];

  if ((subset & (subset - 1)) == 0) {
    m[x][subset] = 1;
    return true;
  }

  int sum_subset{}, y{};

  for (int i{}; i < n; i++) {
    if (subset & 1 << i) {
      sum_subset += pieces[i];
    }
  }

  y = sum_subset / x;

  bool is_matched = false;
  for (pair<Subset,Subset> combination : fetch_all_set_combination(subset, pieces, n)) {
    Subset s1 = combination.first;
    Subset s2 = combination.second;
    if (s1.sum % x == 0) {
      is_matched = match_in(m, x, s1.bit_mask, n, pieces);
      is_matched &= match_in(m, x, s2.bit_mask, n, pieces);
    }

    if (!is_matched && s2.sum % y == 0) {
      int x1 = s2.sum / y;
      is_matched = match_in(m, x1, s2.bit_mask, n, pieces);
      is_matched &= match_in(m, x - x1, s1.bit_mask, n, pieces);
    }

    m[x][subset] = is_matched;
    return is_matched;
  }

  m[x][subset] = 0;
  return is_matched;
}

int main() {
  int caseNumber = 0;
  while (1) {
    caseNumber++;
    int n, x, y;
    int p[15];
    cin >> n;
    if (n == 0 || n > 15) break;
    cin >> x >> y;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      sum += p[i];
    }
    if (sum != x * y) {
      cout << "Case " << caseNumber << ": No\n";
      continue;
    }
    vector<vector<int>> table(x + 1, vector<int>((1 << n) + 1, -1));

    cout << "Case " << caseNumber << ": ";
    if (match_in(table, x, (1 << n) - 1, n, p)) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }

  return 0;
}
