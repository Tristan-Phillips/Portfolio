const generateButton = document.getElementById('generate');
const gridContainer = document.getElementById('container__grid');

function generateRandomColor() {
    const red = Math.floor(Math.random() * 256);
    const green = Math.floor(Math.random() * 256);
    const blue = Math.floor(Math.random() * 256);

    return `rgb(${red}, ${green}, ${blue})`;
}

generateButton.addEventListener('click', function() {
    const gridCells = gridContainer.getElementsByClassName('grid--cell');
    for (const element of gridCells) {
        const cell = element;
        const randomColor = generateRandomColor();
        cell.style.backgroundColor = randomColor;
    }
});

const clearButton = document.getElementById('clear');

clearButton.addEventListener('click', function() {
    const gridCells = gridContainer.getElementsByClassName('grid--cell');
    for (const element of gridCells) {
        const cell = element;
        cell.style.backgroundColor = 'white';
    }
});

const saveButton = document.getElementById('save');

saveButton.addEventListener('click', function() {
    const canvas = document.createElement('canvas');
    const context = canvas.getContext('2d');

    const gridWidth = gridContainer.offsetWidth;
    const gridHeight = gridContainer.offsetHeight;
    canvas.width = gridWidth;
    canvas.height = gridHeight;

    const gridCells = gridContainer.getElementsByClassName('grid--cell');
    for (const element of gridCells) {
        const cell = element;
        const cellStyle = getComputedStyle(cell);
        const cellColor = cellStyle.backgroundColor;
        const cellRect = cell.getBoundingClientRect();


        const cellX = cellRect.left - gridContainer.getBoundingClientRect().left;
        const cellY = cellRect.top - gridContainer.getBoundingClientRect().top;

        context.fillStyle = cellColor;
        context.fillRect(cellX, cellY, cell.offsetWidth, cell.offsetHeight);
    }

    const dataURL = canvas.toDataURL();
    const link = document.createElement('a');
    link.href = dataURL;
    link.download = 'pixel_art.png';
    link.click();
});

window.addEventListener('load', function() {
    const containerGrid = document.getElementById('container__grid');
    const gridSize = 16;

    for (let i = 0; i < gridSize; i++) {
        for (let j = 0; j < gridSize; j++) {
            const gridCell = document.createElement('div');
            gridCell.classList.add('grid--cell');
            containerGrid.appendChild(gridCell);
        }
    }
});

const toggleCheckbox = document.getElementById('toggle');

toggleCheckbox.addEventListener('change', function() {
    if (toggleCheckbox.checked) {
        generateButtonLoop();
    }
});

function generateButtonLoop() {
    generateButton.click();
    if (toggleCheckbox.checked) {
        setTimeout(generateButtonLoop, 100);
    }
}