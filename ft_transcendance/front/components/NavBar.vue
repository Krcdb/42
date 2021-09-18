<template>
  <div class="navbar navbar-expand-lg navbar-light bg-dark">
  	<nav>
  	  <nav-item class="navbar-brand font-bold">
        <NuxtLink to="/" class="text-lg font-bold"> Ft_Transcendance </NuxtLink>
      </nav-item>
  	  <nav-item class="flex-none px-2 mx-2">
        <NuxtLink to="/game" class="text-lg font-bold"> Game </NuxtLink>
      </nav-item>
	  <nav-item class="flex-none px-2 mx-2">
        <NuxtLink to="/leaderboard" class="text-lg font-bold"> Leaderboard </NuxtLink>
      </nav-item>
	  <nav-item class="flex-none px-2 mx-2">
        <NuxtLink to="/chat" class="text-lg font-bold"> Chat </NuxtLink>
      </nav-item>
  	  <nav-item class="flex-none mx-4">
        <NuxtLink to="/profile" class="text-lg font-bold"> Profile </NuxtLink>
      </nav-item>
  	</nav>
  </div>
</template>

<script lang="ts">
import Vue from 'vue'

export default Vue.extend({})
</script>

<style>

</style>