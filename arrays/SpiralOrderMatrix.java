import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class SpiralOrderMatrix {
    /*
     * - Problem:
     * InterviewBit - Spiral Order Matrix
     *
     * - Problem description:
     * Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order.
     */

    private static ArrayList<Integer> spiralOrderMatrix(final List<ArrayList<Integer>> M) {
        ArrayList<Integer> result = new ArrayList<>();
        
        int numRows = M.size();
        if (numRows == 0) return result;
        
        int numCols = M.get(0).size();
        if (numCols == 0) return result;

        // change in the indexes when going right, down, left and up
        int[] dX = {1, 0, -1, 0};
        int[] dY = {0, 1, 0, -1};

        // clock-wise limits (starting from top-left) of the table being considered at each moment
        int borders[][] = {{0, 0}, {0, numCols - 1}, {numRows - 1, numCols - 1}, {numRows - 1, 0}};

        int currRow = 0;
        int currColumn = 0;
        int currDirId = 0; // meaning "start going left"

        result.add(M.get(currRow).get(currColumn));

        while (true) {
            while (!(currRow == borders[(currDirId + 1) % 4][0] && currColumn == borders[(currDirId + 1) % 4][1])) {
                currColumn += dX[currDirId];
                currRow += dY[currDirId];

                result.add(M.get(currRow).get(currColumn));
            }

            // update the borders
            borders[currDirId][0] += dY[(currDirId + 1) % 4];
            borders[currDirId][1] += dX[(currDirId + 1) % 4];
            borders[(currDirId + 1) % 4][0] += dY[(currDirId + 1) % 4];
            borders[(currDirId + 1) % 4][1] += dX[(currDirId + 1) % 4];

            /* Check if all elements were printed by checking if the top-left border crossed the bottom-left or the
            top-right borders */
            if (borders[0][0] > borders[3][0] || borders[0][1] > borders[1][1]) break;

            // change scanning direction
            currDirId = (currDirId + 1) % 4;
        }

        return result;
    }

    public static void main(String[] args) {
        List<ArrayList<Integer>> M = List.of(
                new ArrayList<>(List.of(1, 2, 3)),
                new ArrayList<>(List.of(4, 5, 6)),
                new ArrayList<>(List.of(7, 8, 9))
        );

        System.out.println(Arrays.toString(spiralOrderMatrix(M).toArray()));
    }
}
