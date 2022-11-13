<script lang="ts">
    import { writable } from "svelte/store";

    const width = 3;
    const attr = writable({
        y: 5,
        x: 5,
        rot: 0,
    });

    let lefty = {
        x: 0,
        y: 0,
    };
    window.addEventListener("gamepadconnected", (e) => {
        const gp = navigator.getGamepads()[e.gamepad.index];
        setInterval(() => {
            if (gp) {
                const left = gp.axes[1];
                const right = gp?.axes[5];

                lefty.x =
                    $attr.x -
                    Math.cos($attr.rot / (360 / (2 * Math.PI))) * 0.5 * width;
                lefty.y =
                    $attr.x -
                    Math.sin($attr.rot / (360 / (2 * Math.PI))) * 0.5 * width;
            }
            $attr.rot += 0.1;
        }, 10);
    });
</script>

<div
    class="obj"
    style:top={$attr.y + "rem"}
    style:left={$attr.x + "rem"}
    style:transform={"translate(-50%, -50%) rotate(" + $attr.rot + "deg)"}
/>

<div
    class="dot"
    style:top={lefty.y + "rem"}
    style:left={lefty.x + "rem"}
    style:transform={"translate(-50%, -50%)"}
/>

<style>
    .dot {
        position: fixed;
        width: 5px;
        height: 5px;
        background-color: red;
        z-index: 200;
    }
    .obj {
        position: fixed;
        width: calc(3rem - 2px);
        height: 3rem;
        background-color: grey;
        border-left: 1px solid white;
        border-right: 1px solid white;
    }
</style>
