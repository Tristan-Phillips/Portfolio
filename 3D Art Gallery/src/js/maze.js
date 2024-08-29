function newMaze(x, y){
    let totalCells = x*y; // Total cells in the maze
    let cells = new Array(); // Cells in the maze
    let unvis = new Array(); // Unvisited cells in the maze

    for(let i = 0; i < y; i++){ // Create the cells in the maze
        cells[i] = new Array(); 
        unvis[i] = new Array();
        for(let j = 0; j < x; j++){
            cells[i][j] = [0,0,0,0]; // Top, Right, Bottom, Left
            unvis[i][j] = true; // Mark all cells as unvisited
        }
    }

    let currentCell = [Math.floor(Math.random()*y), Math.floor(Math.random()*x)]; // Random starting cell
    let path = [currentCell]; // Path taken
    unvis[currentCell[0]][currentCell[1]] = false; // Mark the starting cell as visited
    let visited = 1; // Mark the starting cell as visited

    while(visited < totalCells){ // Loop through all cells
        let potential = [[currentCell[0]-1, currentCell[1], 0, 2], // Top - [y, x, side, opposite side]
                            [currentCell[0], currentCell[1]+1, 1, 3], // Right
                            [currentCell[0]+1, currentCell[1], 2, 0], // Bottom
                            [currentCell[0], currentCell[1]-1, 3, 1]]; // Left
        let neighbors = new Array(); // Unvisited neighbors

        for(let l = 0; l < 4; l++){ // Loop through the potential neighbors
            if(potential[l][0] > -1 && potential[l][0] < y && potential[l][1] > -1 && potential[l][1] < x && unvis[potential[l][0]][potential[l][1]]){
                neighbors.push(potential[l]); // Add the neighbor if it's unvisited
            }
        }

        if(neighbors.length){ // If there are any neighbors
            let next = neighbors[Math.floor(Math.random()*neighbors.length)]; // Choose a random neighbor
            cells[currentCell[0]][currentCell[1]][next[2]] = 1; // Knock down the wall between the current cell and the chosen cell
            cells[next[0]][next[1]][next[3]] = 1; // Knock down the wall between the chosen cell and the current cell
            unvis[next[0]][next[1]] = false; // Mark the chosen cell as visited
            visited++; // Increase the visited cell count
            currentCell = [next[0], next[1]]; // Move the current cell to the chosen cell
            path.push(currentCell); // Add the chosen cell to the path
        } else {
            currentCell = path.pop(); // Move the current cell to the previous cell in the path
        }
    }
    return cells; // Return the cells in the maze
}

export function generate_maze(){
    let maze = newMaze(5, 5); // Generate a 5 x 5 maze
    console.log(maze);
    return maze;
} 