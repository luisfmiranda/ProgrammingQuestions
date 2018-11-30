/*
 * - Problem:
 * InterviewBit - Min Steps in Infinite Grid
 *
 * - Problem description:
 * You are in an infinite 2D grid where you can move in any of the 8 directions. You are given a sequence of points and
 * the order in which you need to cover the points. Give the minimum number of steps in which you can achieve it. You
 * start from the first point.
 */

function minStepsInfiniteGrid(x, y) {
    let points = [];

    // array with all the points
    for (let i = 0; i < x.length; i++)
        points.push([x[i], y[i]]);

    let minSteps = 0;

    // at each step of the reduction, sum the steps required to go from point i to point i + 1
    points.reduce(function (start, end) {
        let xDiff = Math.abs(end[0] - start[0]);
        let yDiff = Math.abs(end[1] - start[1]);

        minSteps += xDiff > yDiff ? xDiff : yDiff;

        return end;
    });

    return minSteps;
}

function minStepsInfiniteGridTester() {
    let x = [0, 1, 1];
    let y = [0, 1, 2];

    console.log(minStepsInfiniteGrid(x, y));
}

minStepsInfiniteGridTester();
