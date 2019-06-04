import { postText } from '../api/index';

export default class AppInput extends HTMLElement {
  static get template() {
    return `
      <input class="input" id="input"></input>
      `
  }

  constructor() {
    super();
  }

  connectedCallback() {
    this.attachShadow({
      mode: 'open'
    })
    this.shadowRoot.innerHTML = AppInput.template;
    this.input = this.shadowRoot.querySelector("#input");
    this.input.addEventListener('keypress', e => {
      if (e.key !== 'Enter') return;
      postText(e.target.value);
      e.target.value = '';
    })
  }
}
