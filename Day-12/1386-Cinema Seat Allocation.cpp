//https://leetcode.com/problems/cinema-seat-allocation/description/

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;

        // Bits 2 to 9 represent reserved seats.
        for (auto &r : reservedSeats) {
            int row = r[0];
            int seat = r[1];

            // Only seats 2-9 affect the answer.
            if (seat >= 2 && seat <= 9) {
                rows[row] |= (1 << seat);
            }
        }

        // Every completely empty row can accommodate 2 families.
        int ans = 2 * (n - rows.size());

        // Masks for seats:
        // 2-5, 6-9, 4-7
        int left  = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int right = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);
        int middle = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);

        for (auto &[row, mask] : rows) {
            bool L = (mask & left) == 0;
            bool R = (mask & right) == 0;
            bool M = (mask & middle) == 0;

            if (L && R)
                ans += 2;
            else if (L || R || M)
                ans += 1;
        }

        return ans;
    }
};
