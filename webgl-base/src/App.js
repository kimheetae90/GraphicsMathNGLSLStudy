import React from 'react';
import * as THREE from 'three-full'
/* eslint import/no-webpack-loader-syntax: off */
import vertexShader from './default.vert';
/* eslint import/no-webpack-loader-syntax: off */
import fragmentShader from './default.frag';

class App extends React.Component{
  componentDidMount () {
    var width = window.innerWidth;
    var height = window.innerHeight;
    var scene = new THREE.Scene();
    var camera = new THREE.PerspectiveCamera(75, width / height, 0.1, 1000)

    var renderer = new THREE.WebGLRenderer();
    renderer.setSize(width, height);
    
    var container = document.getElementById('App');
    container.appendChild(renderer.domElement);

    var geometry = new THREE.BoxGeometry( 1, 1, 1 );
    var material = new THREE.ShaderMaterial( {
      vertexShader: vertexShader,
      fragmentShader: fragmentShader
    } );
    var cube = new THREE.Mesh( geometry, material );
    scene.add( cube );

    camera.position.z = 5;

    var animate = function () {
      requestAnimationFrame( animate );

      renderer.render( scene, camera );
    };

    animate();
  }

  render () {
    return (
      <div id="App"></div>
    )
  }
}

export default App;
