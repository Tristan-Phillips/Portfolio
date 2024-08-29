import * as THREE from 'three'
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls.js'
import { construct_map } from './js/map.js'
import { setup_controls } from './js/controls.js'
import { setup_player } from './js/player.js'

/**
 * Base
 */
// Canvas
const canvas = document.querySelector('canvas.webgl')

// Scene
const scene = new THREE.Scene()

/**
 * Lights
 */

// Hemisphere light
const hemisphere_light = new THREE.HemisphereLight(0xffffff, 0x000000, 0.5)
scene.add(hemisphere_light)

// Map
construct_map(scene)

/**
 * Sizes
 */
const sizes = {
    width: innerWidth,
    height: innerHeight
}

/**
 * Camera
 */
// Base camera
const camera = new THREE.PerspectiveCamera(75, sizes.width / sizes.height, 0.1, 100)
camera.position.y = 30
camera.position.z = 0
camera.position.x = 0
camera.fov = 90
camera.updateProjectionMatrix()
camera.lookAt(10, 10 ,10)
//setup_player(camera)
scene.add(camera)

// Bind a sphere to the camera and project a ray from the camera to the sphere
const sphere = new THREE.Mesh(
    new THREE.SphereGeometry(0.05, 32, 32),
    new THREE.MeshBasicMaterial({ color: 0xffffff })
)
camera.add(sphere)

// Controls
const controls = setup_controls(camera, canvas)

/**
 * Renderer
 */
const renderer = new THREE.WebGLRenderer({
    canvas: canvas,
    antialias: true
})
renderer.setSize(sizes.width, sizes.height)

/**
 * Axes Helper
 */

const axesHelper = new THREE.AxesHelper( 5 )
scene.add( axesHelper )

/**
 * Animate
 */
const clock = new THREE.Clock()

const tick = () =>
{
    const elapsedTime = clock.getElapsedTime()

    // Render
    renderer.render(scene, camera)

    // Call tick again on the next frame
    window.requestAnimationFrame(tick)
}

tick()

// Event listner for window resize
window.addEventListener('resize', () => {
    // Update sizes
    sizes.width = window.innerWidth
    sizes.height = window.innerHeight

    // Update camera
    camera.aspect = sizes.width / sizes.height
    camera.updateProjectionMatrix()

    // Update renderer
    renderer.setSize(sizes.width, sizes.height)
    renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))
})
