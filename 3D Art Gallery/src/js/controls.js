// Import the first person controls from three
import { PointerLockControls } from 'three/examples/jsm/controls/PointerLockControls.js'
// Import raycaster from three
import { Raycaster } from 'three'

const sensitivity = {
    x: 0.000001,
    y: 0.000001
}

const key_map = {
    w: 'forward',
    'arrowup': 'forward',
    a: 'left',
    'arrowleft': 'left',
    s: 'backward',
    'arrowdown': 'backward',
    d: 'right',
    'arrowright': 'right',
    ' ': 'jump'
}

let movementSpeed = 0.5 //0.1 later, 0.5 for testing

export function setup_controls(camera, canvas) {
    // Create the controls
    const controls = new PointerLockControls(camera, canvas)
    // lock the pointer on click
    canvas.addEventListener('click', () => {
        controls.lock()
    })
    // set the sensitivity of the controls
    controls.mouseSensitivity = {x: sensitivity.x, y: sensitivity.y}

    // Listen for keydown events
    document.addEventListener('keydown', (event) => {
        // Get the key
        const key = event.key.toLowerCase()
        // Check if the key is mapped
        if (key_map[key]) {
            // Get the direction
            const direction = key_map[key]
            // Move the player
            if (direction == 'forward') {
                controls.moveForward(movementSpeed)
                // Continue the movement for a few milliseconds after the key is released
                setTimeout(() => {
                    controls.moveForward(movementSpeed * 0.1)
                }, 100)
            }
            else if (direction == 'backward') {
                controls.moveForward(movementSpeed * -1)
                // Continue the movement for a few milliseconds after the key is released
                setTimeout(() => {
                    controls.moveForward(movementSpeed * -0.1)
                }, 100)
            }
            else if (direction == 'left') {
                controls.moveRight(movementSpeed * -1)
                // Continue the movement for a few milliseconds after the key is released
                setTimeout(() => {
                    controls.moveRight(movementSpeed * -0.1)
                }, 100)
            }
            else if (direction == 'right') {
                controls.moveRight(movementSpeed)
                // Continue the movement for a few milliseconds after the key is released
                setTimeout(() => {
                    controls.moveRight(movementSpeed * 0.1)
                }, 100)
            } else if (direction == 'jump') {
                // Jump ?

            }
        }
    })
    // Enable control damping
    controls.enableDamping = true

    // set the movement speed of the controls
    controls.movementSpeed = 0.1
    return controls
}

export function update_controls(controls) {
    controls.update()
}