import * as THREE from 'three'
import { floorTexture, wallTexture, ceilingTexture } from './texture'
import { paint_image } from './painting'
import { generate_maze } from './maze'

var floor_tile = {
    height: 10,
    width: 0.1,
    depth: 10,
    color: 0xffffff
}

var wall = {
    height: 8,
    width: 0.1,
    depth: 10,
    color: 0xffffff,
    y: 3.5
}

var ceiling = {
    height: 10,
    width: 0.1,
    depth: 10,
    color: 0xffffff,
    y: 7.5
}

/**
 * Cube - Hallway 
 * - Ceiling
 * - 2 Walls (left and right)
 * - Floor
 */

function construct_cube(scene, position_floor, position_ceiling, position_wall_left, position_wall_right, position_wall_front, position_wall_back) {
    // Group the objects together
    var group = new THREE.Group()
    // Floor
        const floor_geometry = new THREE.BoxGeometry(floor_tile.height, floor_tile.width, floor_tile.depth)
        const floor_material = new THREE.MeshPhongMaterial({ color: floor_tile.color, wireframe: false})
        const floor_mesh = new THREE.Mesh(floor_geometry, floor_material)
        floor_mesh.position.x = position_floor.x
        floor_mesh.position.y = position_floor.y
        floor_mesh.position.z = position_floor.z
        // Add the texture
        floor_mesh.material.map = floorTexture
        // Add to group
        group.add(floor_mesh)

    // left wall
    if(position_wall_left != null){
        const wall_geometry_left = new THREE.BoxGeometry(wall.width, wall.height, wall.depth)
        const wall_material_left = new THREE.MeshBasicMaterial({ color: wall.color, wireframe: false })
        const wall_mesh_left = new THREE.Mesh(wall_geometry_left, wall_material_left)
        wall_mesh_left.position.x = position_wall_left.x
        wall_mesh_left.position.y = position_wall_left.y
        wall_mesh_left.position.z = position_wall_left.z
        // Add the texture
        wall_mesh_left.material.map = wallTexture
        // Add the painting to the center of the wall
        let painting = paint_image(scene, 'public/img/painting01.png', {x: position_wall_left.x+0.1, y: position_wall_left.y-1, z: position_wall_left.z}, {width: 3, height: 4})
        // Rotate the painting
        painting.rotation.y = Math.PI / 2
        group.add(painting)
        // Add to scene
        group.add(wall_mesh_left)
    }
    // right wall
    if(position_wall_right != null) {
        const wall_geometry_right = new THREE.BoxGeometry(wall.width, wall.height, wall.depth)
        const wall_material_right = new THREE.MeshBasicMaterial({ color: wall.color, wireframe: false })
        const wall_mesh_right = new THREE.Mesh(wall_geometry_right, wall_material_right)
        wall_mesh_right.position.x = position_wall_right.x
        wall_mesh_right.position.y = position_wall_right.y
        wall_mesh_right.position.z = position_wall_right.z
        // Add the texture
        wall_mesh_right.material.map = wallTexture
        // Add to scene
        group.add(wall_mesh_right)
    }
    // front wall
    if(position_wall_front != null) {
        const wall_geometry_front = new THREE.BoxGeometry(wall.width, wall.height, wall.depth)
        const wall_material_front = new THREE.MeshBasicMaterial({ color: wall.color, wireframe: false })
        const wall_mesh_front = new THREE.Mesh(wall_geometry_front, wall_material_front)
        wall_mesh_front.position.x = position_wall_front.x
        wall_mesh_front.position.y = position_wall_front.y
        wall_mesh_front.position.z = position_wall_front.z
        // Add the texture
        wall_mesh_front.material.map = wallTexture
        // Rotate the wall
        wall_mesh_front.rotation.y = Math.PI / 2
        // Add to scene
        group.add(wall_mesh_front)
    }
    // // back wall
    if(position_wall_back != null) {
        const wall_geometry_back = new THREE.BoxGeometry(wall.width, wall.height, wall.depth)
        const wall_material_back = new THREE.MeshBasicMaterial({ color: wall.color, wireframe: false })
        const wall_mesh_back = new THREE.Mesh(wall_geometry_back, wall_material_back)
        wall_mesh_back.position.x = position_wall_back.x
        wall_mesh_back.position.y = position_wall_back.y
        wall_mesh_back.position.z = position_wall_back.z
        // Add the texture
        wall_mesh_back.material.map = wallTexture
        // Rotate the wall
        wall_mesh_back.rotation.y = Math.PI / 2
        // Add to scene
        group.add(wall_mesh_back)
    }
    // Ceiling
        const ceiling_geometry = new THREE.BoxGeometry(ceiling.height, ceiling.width, ceiling.depth)
        const ceiling_material = new THREE.MeshBasicMaterial({ color: ceiling.color, wireframe: true })
        const ceiling_mesh = new THREE.Mesh(ceiling_geometry, ceiling_material)
        ceiling_mesh.position.x = position_ceiling.x
        ceiling_mesh.position.y = position_ceiling.y
        ceiling_mesh.position.z = position_ceiling.z
        // Add the texture
        ceiling_mesh.material.map = ceilingTexture
        // Add to scene
        group.add(ceiling_mesh)

    // Lights
        // D

    // Return the cube
    return group
}

// function colorWinningCube(scene, position){
//     const geometry = new THREE.BoxGeometry(floor_tile.height, floor_tile.width, floor_tile.depth)
//     const material = new THREE.MeshPhongMaterial({ color: 0x00ff00, wireframe: false})
//     const mesh = new THREE.Mesh(geometry, material)
//     mesh.position.x = position.x
//     mesh.position.y = position.y
//     mesh.position.z = position.z
//     // Add to scene
//     scene.add(mesh)
// }

export function construct_map(scene) {
    // Generate the maze
    const maze = generate_maze()

    // Generate the map
    // A 10 x 10 grid of cubes
    // for (let x = 0; x < 1; x++) {
    //     for (let z = 0; z < 1; z++) {
    //         if(x == 0){
    //             if(z == 9){ // Top left corner
    //                 scene.add(construct_cube(scene, {x: x*10, y: -0.5, z: z*10}, {x: x*10, y: ceiling.y, z: z*10}, {x: x*10-5, y: wall.y, z: z*10}, null, null, {x: x*10, y: wall.y, z: z*10+5}))
    //             } else if(z == 0){ 
    //                 scene.add(construct_cube(scene, {x: x*10, y: -0.5, z: z*10}, {x: x*10, y: ceiling.y, z: z*10}, {x: x*10-5, y: wall.y, z: z*10}, null, {x: x*10, y: wall.y, z: z*10-5}, null))
    //             } else { 
    //                 scene.add(construct_cube(scene, {x: x*10, y: -0.5, z: z*10}, {x: x*10, y: ceiling.y, z: z*10}, {x: x*10-5, y: wall.y, z: z*10}, null, null, null))
    //             }
    //         } else if(x == 9){ // Top right corner
    //             if(z == 9){ 
    //                 scene.add(construct_cube(scene, {x: x*10, y: -0.5, z: z*10}, {x: x*10, y: ceiling.y, z: z*10}, null, {x: x*10+5, y: wall.y, z: z*10}, null, {x: x*10, y: wall.y, z: z*10+5}))
    //             } else if(z == 0){ 
    //                 scene.add(construct_cube(scene, {x: x*10, y: -0.5, z: z*10}, {x: x*10, y: ceiling.y, z: z*10}, null, {x: x*10+5, y: wall.y, z: z*10}, {x: x*10, y: wall.y, z: z*10-5}, null))
    //             } else { 
    //                 scene.add(construct_cube(scene, {x: x*10, y: -0.5, z: z*10}, {x: x*10, y: ceiling.y, z: z*10}, null, {x: x*10+5, y: wall.y, z: z*10}, null, null))
    //             }
    //         } else if(z == 9){ // Bottom left corner
    //             scene.add(construct_cube(scene, {x: x*10, y: -0.5, z: z*10}, {x: x*10, y: ceiling.y, z: z*10}, null, null, null, {x: x*10, y: wall.y, z: z*10+5}))
    //         } else if(z == 0){ // Bottom right corner
    //             scene.add(construct_cube(scene, {x: x*10, y: -0.5, z: z*10}, {x: x*10, y: ceiling.y, z: z*10}, null, null, {x: x*10, y: wall.y, z: z*10-5}, null))
    //         } else { // Normal cube
    //             scene.add(construct_cube(scene, {x: x*10, y: -0.5, z: z*10}, {x: x*10, y: ceiling.y, z: z*10}, null, null, null, null))
    //         }
    //     }
    // }

    // Add the maze to the map
    for(let i = 0; i < maze.length; i++){
        for(let j = 0; j < maze[i].length; j++){
            if(maze[i][j][0] == 0){ // Top
                scene.add(construct_cube(scene, {x: j*10, y: -0.5, z: i*10}, {x: j*10, y: ceiling.y, z: i*10}, null, null, {x: j*10, y: wall.y, z: i*10-5}, null))
            }
            if(maze[i][j][1] == 0){ // Right
                scene.add(construct_cube(scene, {x: j*10, y: -0.5, z: i*10}, {x: j*10, y: ceiling.y, z: i*10}, null, {x: j*10+5, y: wall.y, z: i*10}, null, null))
            }
            if(maze[i][j][2] == 0){ // Bottom
                scene.add(construct_cube(scene, {x: j*10, y: -0.5, z: i*10}, {x: j*10, y: ceiling.y, z: i*10}, null, null, null, {x: j*10, y: wall.y, z: i*10+5}))
            }
            if(maze[i][j][3] == 0){ // Left
                scene.add(construct_cube(scene, {x: j*10, y: -0.5, z: i*10}, {x: j*10, y: ceiling.y, z: i*10}, {x: j*10-5, y: wall.y, z: i*10}, null, null, null))
            }
            // if(i == maze.length - 5 && j == maze.length - 1){
            //     colorWinningCube(scene, {x: j*10, y: -0.5, z: i*10})
            //     // Remove the boundary wall?
            // }
        }
    }
}