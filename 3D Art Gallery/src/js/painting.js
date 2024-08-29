import * as THREE from 'three'

// Turn an image into a box painted with the image
export function paint_image(scene, image, position, size) {
    const geometry = new THREE.BoxGeometry(size.width, size.height, 0.1)
    const material = new THREE.MeshBasicMaterial({ color: 0xffffff })
    const mesh = new THREE.Mesh(geometry, material)
    mesh.position.x = position.x
    mesh.position.y = position.y
    mesh.position.z = position.z

    // Add the texture
    const texture = new THREE.TextureLoader().load(image)
    mesh.material.map = texture

    return mesh
}