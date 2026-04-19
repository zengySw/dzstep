import { render, screen } from '@testing-library/react';
import App from './App';

test('renders header and products navigation', () => {
  render(<App />);

  expect(screen.getByText(/shop master page/i)).toBeInTheDocument();
  expect(screen.getByRole('link', { name: /products from json/i })).toBeInTheDocument();
});
