import * as THREE from 'three'

// Texture loader
const textureLoader = new THREE.TextureLoader()

// Textures
const floorTexture = textureLoader.load('public/textures/floor.png')
floorTexture.wrapS = THREE.RepeatWrapping
floorTexture.wrapT = THREE.RepeatWrapping
floorTexture.repeat.x = 1
floorTexture.repeat.y = 1

const wallTexture = textureLoader.load('public/textures/wall.png')
wallTexture.wrapS = THREE.RepeatWrapping
wallTexture.wrapT = THREE.RepeatWrapping
wallTexture.repeat.x = 1
wallTexture.repeat.y = 1

const ceilingTexture = textureLoader.load('public/textures/ceiling.png')
ceilingTexture.wrapS = THREE.RepeatWrapping
ceilingTexture.wrapT = THREE.RepeatWrapping
ceilingTexture.repeat.x = 1
ceilingTexture.repeat.y = 1

export { floorTexture, wallTexture, ceilingTexture }