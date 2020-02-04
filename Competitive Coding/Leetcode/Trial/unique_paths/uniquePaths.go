package unique_paths

var tot_paths int = 0

func findPaths(x int, y int, endx int, endy int) {
	if x > endx || y > endy {
		return
	}
	if x == endx && y == endy {
		tot_paths += 1
		return
	}

	findPaths(x+1, y, endx, endy)
	findPaths(x, y+1, endx, endy)
}

func UniquePaths(m int, n int) int {

	mat := make([][]int, m)
	for i := 0; i < m; i++ {
		mat[i] = make([]int, n)
	}
	// set first row and col as 1
	for i := 0; i < m; i++ {
		mat[i][0] = 1
	}
	for j := 0; j < n; j++ {
		mat[0][j] = 1
	}

	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			mat[i][j] = mat[i-1][j] + mat[i][j-1]
		}
	}
	// fmt.Printf("%#v \n", mat)
	return mat[m-1][n-1]
}
